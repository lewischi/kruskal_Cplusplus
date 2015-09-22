#include <algorithm>
#include "pts.h"

Pts::Pts() {
} // SPts()

Pts::Pts(int numElements) {
  e = numElements;
  parent = new int[e];
  fill(parent, parent + e - 1);
} // Pts

Pts::~Pts() { } // ~Pts

int Pts::collapsingFind(int x) {
  int temp; 
  for(temp = x; parent[temp] >= 0; temp = parent[temp]);
  return temp;
} // collapsingFind()

bool Pts::has(int val) {
  for (int i = 0; i < n; i++)
    if (parent[i] == val) return true; // if
  return false;
} // Has()  sets.cpp 29 COMBINE///////////////////

void Pts::insert(int v) {
  if (has(i)) return;
  while (i > n) {
    if (n == 0) {
      n = 1;
      parent = new int[1]();
      continue;
    } // 
    int *temp = parent;
    parent = new int[n * 2]();
    for (int i = 0; i < n * 2; i++) parent[i] = temp[i];
  } // while value greater than number allowed
  parent[v] = -1;
} // insert()

void Pts::weightedUnion(int x, int y) {
  int temp = parent[x] + parent[y];
  if(parent[x] + parent[y]) {
    parent[x] = y;
    parent[y] = temp;
  }
  else {
    parent[y] = x;
    parent[x] = temp;
  }
} // weightedUnion()

void Pts::quickUnion(int x, int y) {
  parent[x] = y;
  parent[collapsingFind(y)]--;
} // quickUnion() 

int Pts::getParent(int x) {
  if(x > n) throw "Out of bounds!";
  return parent[i];
} // getParent()     CHECK IF FUNCTION NEEDED

Pts & Pts::operator =(Pts& right) {
  n = right.h;
  parent = right.parent;
  return *this;
} // operator = 

ostream & operator<<(ostream& os, const Pts& e) {
  os << "Set contains: ";
   for (int i = 0; i < e.n; i++)
    os << e.parent[i] << ' ';
  os << endl;
  return os;
} // operator <<      CHECK IF NEEDED
