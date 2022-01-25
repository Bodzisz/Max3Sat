//
// Created by bodzisz on 05.01.2022.
//

#include "GeneticIndividual.h"

void GeneticIndividual::addSolution(int variable, bool value)
{
    genotype.insert({variable, value});
}

std::tr1::unordered_map<int, bool> GeneticIndividual::getGenotype()
{
    return genotype;
}
