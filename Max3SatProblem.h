//
// Created by bodzisz on 04.01.2022.
//

#ifndef MAX3SATPROBLEM_MAX3SATPROBLEM_H
#define MAX3SATPROBLEM_MAX3SATPROBLEM_H

#include <vector>
#include <string>
#include <tr1/unordered_map>
#include <set>

class Max3SatProblem
{
    std::vector<std::vector<int>> clauses;
    std::set<int> variables;

public:
    Max3SatProblem();
    Max3SatProblem(std::string path);
    void printClauses();
    std::vector<std::vector<int>> load(std::string path);
    float compute(std::tr1::unordered_map<int, bool> solutions);
    std::vector<std::vector<int>> getClauses();
    std::set<int> getVariables();


};


#endif //MAX3SATPROBLEM_MAX3SATPROBLEM_H
