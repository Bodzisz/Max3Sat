//
// Created by bodzisz on 04.01.2022.
//

#ifndef MAX3SATPROBLEM_SATOPTIMIZER_H
#define MAX3SATPROBLEM_SATOPTIMIZER_H

#include "GeneticOptimizer.h"
#include "SatIndividual.h"
#include <cstdlib>
#include <utility>

class SatOptimizer : public GeneticOptimizer
{
    std::vector<std::vector<int>> clauses;
    std::set<int> variables;

public:
    SatOptimizer();
    SatOptimizer(std::vector<std::vector<int>> clauses, std::set<int> variables, float crossingProb, float mutationProb);
    void initialize() override;
    void runIteration() override;
    SatIndividual chooseParent();
    std::pair<SatIndividual, SatIndividual> crossOver(SatIndividual parent1, SatIndividual parent2);
    std::tr1::unordered_map<int, bool> getSolution();
};


#endif //MAX3SATPROBLEM_SATOPTIMIZER_H
