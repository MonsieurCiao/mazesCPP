
#include <iostream>
#include "cell.h"

using namespace std;

bool found = false;
void dfsRecursive(vector<vector<Cell>> &grid, int i, int j)
{
  Cell cur = grid[i][j];
  // check if end
  if (cur.end)
  {
    found = true;
    return;
  }
  // while neighbors -> choose random neighbor
  vector<Cell *> neighbors = cur.neighbors;

  while (!neighbors.empty() && !found)
  {
    int index = rand() % neighbors.size();
    Cell *newCell = neighbors[index];
    dfsRecursive(grid, newCell->i, newCell->j);

    neighbors.erase(neighbors.begin() + index);
  }
}