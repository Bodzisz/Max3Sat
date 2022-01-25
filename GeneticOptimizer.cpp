//
// Created by bodzisz on 05.01.2022.
//

#include "GeneticOptimizer.h"
#include "SatIndividual.h"

GeneticOptimizer::GeneticOptimizer()
: crossingProb(0.0), mutationProb(0.0)
{
}

GeneticOptimizer::GeneticOptimizer(float crossingProb, float mutationProb)
: crossingProb(crossingProb), mutationProb(mutationProb)
{
}
