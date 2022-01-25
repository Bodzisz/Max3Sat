//
// Created by bodzisz on 05.01.2022.
//

#ifndef MAX3SATPROBLEM_GENETICINDIVIDUAL_H
#define MAX3SATPROBLEM_GENETICINDIVIDUAL_H

#include <tr1/unordered_map>
#include <vector>

class GeneticIndividual
{
protected:
    std::tr1::unordered_map<int, bool> genotype;

public:
    GeneticIndividual()= default;;
    //virtual void crossOver() = 0;
    virtual void mutation(float prob) = 0;
    virtual float fitness(std::vector<std::vector<int>> clauses) = 0;
    void addSolution(int variable, bool value);
    std::tr1::unordered_map<int, bool> getGenotype();
};


#endif //MAX3SATPROBLEM_GENETICINDIVIDUAL_H
