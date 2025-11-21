#include "prim.h"
#include <cstdlib>

using namespace std;

void findFrontiers(int x, int y, vector<Cell *> &frontiers, vector<vector<Cell>> &grid)
{
  // add neighbors to frontiers
  for (int i = x - 1; i <= x + 1; i++)
  {
    for (int j = y - 1; j <= y + 1; j++)
    {
      if ((i == x && j == y) || (i != x && j != y))
      {
        continue;
      }
      if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        continue;
      if (grid[i][j].visited)
        continue;
      // is eligible for frontier
      frontiers.emplace_back(&grid[i][j]); // ptr!!
    }
  }
}
void prim(vector<vector<Cell>> &grid)
{
  vector<Cell *> frontiers;

  // pick random cell
  int randX = std::rand() % grid.size();
  int randY = std::rand() % grid[0].size();
  Cell *currentCell = &grid[randX][randY];
  currentCell->visited = true;

  findFrontiers(randX, randY, frontiers, grid);

  while (!frontiers.empty())
  {
    // choose random frontier
    int frontierI = std::rand() % frontiers.size();
    Cell *frontier = frontiers[frontierI];
    // frontiers.erase(frontiers.begin() + frontierI); // inefficient
    frontiers[frontierI] = frontiers.back();
    frontiers.pop_back();
    frontier->visited = true;

    vector<Cell *> visitedNeighbors;
    for (int i = -1; i <= 1; i++)
    {
      for (int j = -1; j <= 1; j++)
      {
        if ((i == 0 && j == 0) || (i != 0 && j != 0))
        {
          continue;
        }
        int ni = frontier->i + i, nj = frontier->j + j;
        if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size())
          continue;
        if (grid[ni][nj].visited)
          visitedNeighbors.emplace_back(&grid[ni][nj]);
      }
    }
    if (!visitedNeighbors.empty())
    {
      Cell *neighbor = visitedNeighbors[std::rand() % visitedNeighbors.size()];
      // neighbor->neighbors.push_back(frontier);
      frontier->neighbors.push_back(neighbor);
    }

    // add former frontier's frontiers xD
    findFrontiers(frontier->i, frontier->j, frontiers, grid);
  }
}