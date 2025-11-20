#include <iostream>
#include "cell.h"

using namespace std;

void recursiveBacktracking(vector<vector<Cell>> &grid, int i, int j)
{
  Cell *curCell = &grid[i][j];
  curCell->visited = true;
  vector<Cell *> neighbors;

  const int iOffsets[4] = {-1, 0, 1, 0};
  const int jOffsets[4] = {0, -1, 0, 1};

  for (int k = 0; k < 4; k++)
  {
    int ni = i + iOffsets[k];
    int nj = j + jOffsets[k];
    if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size())
      continue;
    if (grid[ni][nj].visited == true)
      continue;
    neighbors.emplace_back(&grid[ni][nj]);
  }
  while (!neighbors.empty())
  {
    int index = std::rand() % neighbors.size();
    Cell *newCell = neighbors[index];
    newCell->neighbors.push_back(curCell);
    curCell->neighbors.push_back(newCell);
    neighbors.erase(neighbors.begin() + index);
    recursiveBacktracking(grid, newCell->i, newCell->j);

    neighbors.clear();
    for (int k = 0; k < 4; k++)
    {
      int ni = i + iOffsets[k];
      int nj = j + jOffsets[k];
      if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size())
        continue;
      if (grid[ni][nj].visited == true)
        continue;
      neighbors.emplace_back(&grid[ni][nj]);
    }
  }
  return;
}