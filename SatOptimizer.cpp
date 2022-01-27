//
// Created by bodzisz on 04.01.2022.
//

#include "SatOptimizer.h"

#include <utility>

SatOptimizer::SatOptimizer() : GeneticOptimizer()
{
}

SatOptimizer::SatOptimizer(float crossingProb, float mutationProb) : GeneticOptimizer(crossingProb, mutationProb)
{
}

SatOptimizer::SatOptimizer(std::vector<std::vector<int>> clauses, std::set<int> variables, float crossingProb, float mutationProb)
: GeneticOptimizer(crossingProb, mutationProb, std::move(clauses), std::move(variables))
{
}

void SatOptimizer::runIteration()
{
    std::vector<SatIndividual> newPopulation;
    while(newPopulation.size() < population.size())
    {
        SatIndividual parent1 = chooseParent();
        SatIndividual parent2 = chooseParent();
        std::pair<SatIndividual, SatIndividual> children = crossOver(parent1, parent2);
        children.first.mutation(mutationProb);
        children.second.mutation(mutationProb);
        newPopulation.push_back(children.first);
        newPopulation.push_back(children.second);
    }

    population = newPopulation;
}

void SatOptimizer::initialize()
{
    for(int i = 0; i < variables.size() * 2; i++)
    {
        SatIndividual individual(variables);
        population.push_back(individual);
    }
}

SatIndividual SatOptimizer::chooseParent()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 100); // define the range

    int firstParticipantIndex = distr(gen) % population.size();
    int secondParticipantIndex = distr(gen) % population.size();
    if(population[firstParticipantIndex].fitness(clauses) > population[secondParticipantIndex].fitness(clauses))
    {
        return SatIndividual(population[firstParticipantIndex].getGenotype());
    }
    else
    {
        return SatIndividual(population[secondParticipantIndex].getGenotype());
    }
}

std::pair<SatIndividual, SatIndividual> SatOptimizer::crossOver(SatIndividual parent1, SatIndividual parent2)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 100); // define the range

    float prob = (float)distr(gen) / 100;
    if(prob < crossingProb)
    {
        return parent1.crossOver(parent2, variables);
    }
    else
    {
        return {SatIndividual(parent1.getGenotype()), SatIndividual(parent2.getGenotype())};
    }
}

std::tr1::unordered_map<int, bool> SatOptimizer::getSolution()
{
    int index = 0;
    float bestFitness = -0.1;
    for(int i = 0; i < population.size(); i++)
    {
        float tempFitness = population[i].fitness(clauses);
        if(tempFitness > bestFitness)
        {
            index = i;
            bestFitness = tempFitness;
        }
    }
    return population[index].getGenotype();
}



