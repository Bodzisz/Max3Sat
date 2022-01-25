//
// Created by bodzisz on 05.01.2022.
//

#ifndef MAX3SATPROBLEM_GENETICOPTIMIZER_H
#define MAX3SATPROBLEM_GENETICOPTIMIZER_H

#include "GeneticIndividual.h"
#include "SatIndividual.h"
#include <vector>
#include <set>

class GeneticOptimizer
{
protected:
    float crossingProb;
    float mutationProb;
    std::vector<SatIndividual> population;

public:
    GeneticOptimizer();
    GeneticOptimizer(float crossingProb, float mutationProb);
    virtual void initialize() = 0;
    virtual void runIteration() = 0;
};


#endif //MAX3SATPROBLEM_GENETICOPTIMIZER_H
