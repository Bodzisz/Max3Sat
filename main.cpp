#include <iostream>
#include "Max3SatProblem.h"
#include "SatOptimizer.h"

int main()
{
    GeneticOptimizer* optimizer = new SatOptimizer(0.9, 0.02);
    for(int i = 0; i < 50; i++)
    {
        // Edit your path here
        Max3SatProblem sat("/home/bodzisz/University/Max3SatProblem/max3sat/50/m3s_50_" + std::to_string(i) + ".txt",
                           optimizer, 20);
        sat.runOptimizer();
        std::cout << i + 1 << ". " <<  sat.getSolutionFitness() << std::endl;
    }

    delete optimizer;

    return 0;
}
