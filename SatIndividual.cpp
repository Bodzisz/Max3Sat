//
// Created by bodzisz on 04.01.2022.
//

#include "SatIndividual.h"

SatIndividual::SatIndividual()
{
}

SatIndividual::SatIndividual(const std::set<int> &variables)
{
    createRandomSolution(variables);
}

std::pair<SatIndividual, SatIndividual> SatIndividual::crossOver(SatIndividual other, const std::set<int>& variables)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 2); // define the range

    std::tr1::unordered_map<int, bool> firstChildGenotype;
    std::tr1::unordered_map<int, bool> secondChildGenotype;
    std::set<int>::iterator itr;
    for (itr = variables.begin(); itr != variables.end(); itr++) {
        if(distr(gen) % 2 == 0)
        {
            firstChildGenotype.insert({*itr, genotype[*itr]});
            secondChildGenotype.insert({*itr, other.genotype[*itr]});
        }
        else
        {
            secondChildGenotype.insert({*itr, genotype[*itr]});
            firstChildGenotype.insert({*itr, other.genotype[*itr]});
        }
    }
    return {SatIndividual(firstChildGenotype), SatIndividual(secondChildGenotype)};
}

void SatIndividual::mutation(float prob)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 100); // define the range

    for (auto& x : genotype)
    {
        float tempProb = (float)distr(gen) / 100;
        if(tempProb < prob)
        {
            genotype[x.first] = !x.second;
        }
    }
}

float SatIndividual::fitness(std::vector<std::vector<int>> clauses)
{
    int fulfilled = 0;
    for(int i = 0; i < clauses.size(); i++)
    {
        for(int x : clauses[i])
        {
            if((x >= 0 && genotype[x]) || (x < 0 && !genotype[-1 * x]))
            {
                fulfilled++;
                break;
            }
        }
    }

    return fulfilled / (float)clauses.size();
}

void SatIndividual::createRandomSolution(const std::set<int>& variables)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 2); // define the range

    std::set<int>::iterator itr;
    for (itr = variables.begin(); itr != variables.end(); itr++) {

        if(distr(gen) % 2 == 0)
        {
            genotype.insert({*itr, true});
        }
        else
        {
            genotype.insert({*itr, false});
        }
    }
}

SatIndividual::SatIndividual(std::tr1::unordered_map<int, bool> genotype)
{
    this->genotype = genotype;
}

std::tr1::unordered_map<int, bool> SatIndividual::getGenotype()
{
    return genotype;
}



