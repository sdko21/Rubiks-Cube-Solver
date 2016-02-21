//
// Created by nathan on 11/02/16.
//

#ifndef RUBKIS_SOLVER_H
#define RUBKIS_SOLVER_H

#include "rCube.hpp"
#include <stack>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>


class solver {

public:

    /*
     * Constructs the object that can do solving
     * of a rubiks cube
     */
    solver();

    /*
     * This funciton uses A* IDS to find a solution
     * It takes a cube and edits it in place
     */
    void AStarIDS(rCube * cubeToSolve, int depth);

    /*
     * Gathers all possible states at current state
     * returns an array of states
     */
    void getCurrentStates(rCube &currentState);


    /*
     * Finds the 3d Manhattan distance between two points X and Y
     * Using  |x1−x2|+|y1−y2|+|z1−z2| = what is returned
     */
    int MH3D(int x1, int y1, int z1,
            int x2, int y2, int z2);


    /*
     * Counts how many tiles are not in the correct place
     */
    int cubesOutOfPlace(rCube &cube);

    /*
     * Solver to try upto 18 random moves
     */
    void randomSolver(rCube &cube);


private:


    std::vector<rCube> visited;

    std::priority_queue<rCube, std::vector<rCube>, rCube::compareF> frontier;

};


#endif //RUBKIS_SOLVER_H
