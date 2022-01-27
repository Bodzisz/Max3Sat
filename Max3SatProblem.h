//
// Created by bodzisz on 04.01.2022.
//

#ifndef MAX3SATPROBLEM_MAX3SATPROBLEM_H
#define MAX3SATPROBLEM_MAX3SATPROBLEM_H

#include <vector>
#include <string>
#include <tr1/unordered_map>
#include <set>
#include "GeneticOptimizer.h"

class Max3SatProblem
{
    std::vector<std::vector<int>> clauses;
    std::set<int> variables;
    GeneticOptimizer* optimizer;
    int iterations;

public:
    Max3SatProblem();
    Max3SatProblem(std::string path, GeneticOptimizer* optimizer, int iterations);
    void printClauses();
    void load(std::string path);
    void runOptimizer();
    float compute(std::tr1::unordered_map<int, bool> solutions);
    std::vector<std::vector<int>> getClauses();
    std::set<int> getVariables();
    std::tr1::unordered_map<int, bool> getSolution();


};


#endif //MAX3SATPROBLEM_MAX3SATPROBLEM_H
