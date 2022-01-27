//
// Created by bodzisz on 04.01.2022.
//

#ifndef MAX3SATPROBLEM_SATINDIVIDUAL_H
#define MAX3SATPROBLEM_SATINDIVIDUAL_H

#include <set>
#include <cstdlib>
#include <iterator>
#include <utility>
#include <random>
#include <tr1/unordered_map>

class SatIndividual
{
private:
    std::tr1::unordered_map<int, bool> genotype;

public:
    SatIndividual();
    explicit SatIndividual(const std::set<int>& variables);
    explicit SatIndividual(std::tr1::unordered_map<int, bool> genotype);
    void createRandomSolution(const std::set<int>& variables);
    std::pair<SatIndividual, SatIndividual> crossOver(SatIndividual other, const std::set<int>& variables);
    void mutation(float prob);
    float fitness(std::vector<std::vector<int>> clauses);
    std::tr1::unordered_map<int, bool> getGenotype();

};


#endif //MAX3SATPROBLEM_SATINDIVIDUAL_H
