cmake_minimum_required(VERSION 3.21)
project(Max3SatProblem)

set(CMAKE_CXX_STANDARD 11)

add_executable(Max3SatProblem main.cpp Max3SatProblem.cpp Max3SatProblem.h SatOptimizer.cpp SatOptimizer.h SatIndividual.cpp SatIndividual.h GeneticOptimizer.cpp GeneticOptimizer.h GeneticIndividual.cpp GeneticIndividual.h)
