#include "dfs.h"

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