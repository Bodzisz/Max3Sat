//
// Created by bodzisz on 04.01.2022.
//

#include "Max3SatProblem.h"
#include <fstream>
#include <iostream>
#include <utility>

Max3SatProblem::Max3SatProblem()
{
}


Max3SatProblem::Max3SatProblem(std::string path)
{
    clauses = load(std::move(path));
}

std::vector<std::vector<int>> Max3SatProblem::load(std::string path)
{
    std::ifstream file(path);
    std::vector<std::vector<int>> result;

    if(file.is_open())
    {
        std::vector<int> temp;
        while(file)
        {
            std::string line;
            file >> line;
            if(line[0] == '(')
            {
                temp.clear();
            }
            else if(line[0] == ')')
            {
                result.push_back(temp);
            }
            else if(line[0] == '-' || (line[0] > 47 && line[0] < 58))
            {
                temp.push_back(std::stoi(line));
            }
        }
    }
    else
    {
        std::cout << "FILE NOT OPENED!" << std::endl;
    }

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            if(result[i][j] < 0)
            {
                variables.insert(-1 * result[i][j]);
            }
            else
            {
                variables.insert(result[i][j]);
            }
        }
    }

    clauses = result;

    return result;
}

void Max3SatProblem::printClauses()
{
    for(int i = 0; i < clauses.size(); i++)
    {
        for(int x : clauses[i])
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

float Max3SatProblem::compute(std::tr1::unordered_map<int, bool> solutions)
{
    int fulfilled = 0;
    for(int i = 0; i < clauses.size(); i++)
    {
        for(int x : clauses[i])
        {
            if((x >= 0 && solutions[x]) || (x < 0 && !solutions[-1 * x]))
            {
                fulfilled++;
                break;
            }
        }
    }

    return fulfilled / (float)clauses.size();
}

std::vector<std::vector<int>> Max3SatProblem::getClauses()
{
    return clauses;
}

std::set<int> Max3SatProblem::getVariables()
{
    return variables;
}


