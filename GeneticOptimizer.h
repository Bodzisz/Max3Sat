//
// Created by bodzisz on 05.01.2022.
//

#ifndef MAX3SATPROBLEM_GENETICOPTIMIZER_H
#define MAX3SATPROBLEM_GENETICOPTIMIZER_H

#include "SatIndividual.h"
#include <vector>
#include <set>

class GeneticOptimizer
{
protected:
    float crossingProb;
    float mutationProb;
    std::vector<SatIndividual> population;
    std::vector<std::vector<int>> clauses;
    std::set<int> variables;

public:
    GeneticOptimizer();
    GeneticOptimizer(float crossingProb, float mutationProb);
    GeneticOptimizer(float crossingProb, float mutationProb, std::vector<std::vector<int>> newClauses, std::set<int> newVariables);
    virtual void initialize() = 0;
    virtual void runIteration() = 0;
    virtual std::tr1::unordered_map<int, bool> getSolution() = 0;
    virtual float getSolutionFitness() = 0;
    void setClauses(std::vector<std::vector<int>> newClauses);
    void setVariables(std::set<int> newVariables);
};


#endif //MAX3SATPROBLEM_GENETICOPTIMIZER_H
