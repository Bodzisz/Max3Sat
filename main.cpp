#include <iostream>
#include "Max3SatProblem.h"
#include "SatOptimizer.h"

int main()
{
    for(int i = 0; i < 50; i++)
    {
        // Edit your path here
        Max3SatProblem sat("/home/bodzisz/University/Max3SatProblem/max3sat/50/m3s_50_" + std::to_string(i) + ".txt");
        SatOptimizer optimizer(sat.getClauses(), sat.getVariables(), 0.9, 0.02);
        optimizer.initialize();
        for (int j = 0; j < 100; j++)
        {
            optimizer.runIteration();
        }
        std::tr1::unordered_map<int, bool> solution = optimizer.getSolution();
        std::cout << sat.compute(solution) << std::endl;
    }

    return 0;
}
