//
// Created by bodzisz on 05.01.2022.
//

#include "GeneticOptimizer.h"

#include <utility>
#include "SatIndividual.h"

GeneticOptimizer::GeneticOptimizer()
: crossingProb(0.0), mutationProb(0.0)
{
}

GeneticOptimizer::GeneticOptimizer(float crossingProb, float mutationProb)
: crossingProb(crossingProb), mutationProb(mutationProb)
{
}

GeneticOptimizer::GeneticOptimizer(float crossingProb, float mutationProb, std::vector<std::vector<int>> newClauses, std::set<int> newVariables)
: crossingProb(crossingProb), mutationProb(mutationProb), clauses(std::move(newClauses)), variables(std::move(newVariables))
{
}

void GeneticOptimizer::setClauses(std::vector<std::vector<int>> newClauses)
{
    clauses = std::move(newClauses);
}

void GeneticOptimizer::setVariables(std::set<int> newVariables)
{
    variables = std::move(newVariables);
}

