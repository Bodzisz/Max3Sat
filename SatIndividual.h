//
// Created by bodzisz on 04.01.2022.
//

#ifndef MAX3SATPROBLEM_SATINDIVIDUAL_H
#define MAX3SATPROBLEM_SATINDIVIDUAL_H

#include "GeneticIndividual.h"
#include <set>
#include <cstdlib>
#include <iterator>
#include <utility>
#include <random>

class SatIndividual : public GeneticIndividual
{
public:
    SatIndividual();
    explicit SatIndividual(const std::set<int>& variables);
    explicit SatIndividual(std::tr1::unordered_map<int, bool> genotype);
    void createRandomSolution(const std::set<int>& variables);
    //void crossOver() override;
    std::pair<SatIndividual, SatIndividual> crossOver(SatIndividual other, const std::set<int>& variables);
    void mutation(float prob) override;
    float fitness(std::vector<std::vector<int>> clauses) override;

};


#endif //MAX3SATPROBLEM_SATINDIVIDUAL_H
