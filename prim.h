#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include "cell.h"

using namespace std;

void findFrontiers(int x, int y, vector<Cell *> &frontiers, vector<vector<Cell>> &grid);

void prim(vector<vector<Cell>> &grid);

#endif