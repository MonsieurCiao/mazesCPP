#pragma once
#include <iostream>

using namespace std;

class Cell
{
public:
  int i;
  int j;
  bool visited = false;
  vector<Cell *> neighbors;
  bool start = false;
  bool end = false;
};