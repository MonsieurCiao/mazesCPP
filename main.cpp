#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "prim.h"
// #include "recursiveBacktracking.h"
// #include "dfsRecursive.h"

#include <stack>

using namespace std;
using namespace std::chrono;

void dfs(vector<vector<Cell>> &grid, int i, int j)
{
  stack<Cell *> stack;
  stack.push(&grid[i][j]);
  while (!stack.empty())
  {
    Cell *cur = stack.top();

    if (cur->end)
    {
      return;
    }
    if (!cur->neighbors.empty())
    {
      int index = rand() % cur->neighbors.size();
      i = cur->neighbors[index]->i;
      j = cur->neighbors[index]->j;
      stack.push(cur->neighbors[index]);
      cur->neighbors.erase(cur->neighbors.begin() + index);
    }
    else
    {
      stack.pop();
      if (stack.empty())
        return;
      cur = stack.top();
    }
  }
  return;
}

void cleanGrid(vector<vector<Cell *>> &grid)
{
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      grid[i][j]->visited = false;
    }
  }
}
void callDFS(vector<vector<Cell>> &grid)
{
  auto start = high_resolution_clock::now();
  dfs(grid, 0, 0);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "dfs done in " << duration.count() << "e-6 seconds" << endl;
}
int main()
{
  srand(time(nullptr)); // seed randomizer
  int m = 1000;
  int n = 1000;
  vector<vector<Cell>> primGrid(m, vector<Cell>(n));
  vector<vector<Cell>> rBGrid(m, vector<Cell>(n));

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      primGrid[i][j].i = i;
      primGrid[i][j].j = j;
      rBGrid[i][j].i = i;
      rBGrid[i][j].j = j;
      // std::cout << primGrid[i][j].i << primGrid[i][j].j << " ";
    }
    // std::cout << endl;
  }

  cout << "starting generation..." << endl;
  auto start = high_resolution_clock::now();
  prim(primGrid);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "prim maze generated in " << duration.count() << endl;

  primGrid[0][0].start = true;
  primGrid[m - 1][n - 1].end = true;
  rBGrid[0][0].start = true;
  rBGrid[m - 1][n - 1].end = true;

  callDFS(primGrid);

  cout << "done \n\n";

  while (true)
  {
    cout << "Wanna go again?" << endl
         << "select algorithm:" << endl;
    cout << "1 - DFS" << endl;
    cout << "0 - terminate" << endl;
    int algoInt;
    cin >> algoInt;
    if (algoInt == 0)
      return 0;
    else if (algoInt == 1)
      callDFS(primGrid);
  }
  return 0;
}
