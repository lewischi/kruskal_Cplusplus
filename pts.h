#ifndef SETS_H
#define	SETS_H

#include <iostream>
using namespace std;

class Region;
class Edge;

class Pts {
  friend void kruskal(Region *region, Edge *ePts, Pts *vPts);
  friend void output(Region *region, Edge *ePts, Pts vPts, int verts, int edges);
  friend ostream & operator<<(ostream& os, const Pts& e)
public:
  Pts();
  Pts(int numElements);
  ~Pts();
  int collapsingFind(int x);
  void weightedUnion(int x, int y);
  void quickUnion(int x, int y);
// bool Has
  void insert(int i);
  int getParent(int p);
  Pts & operator=(Pts& rhs);
  int *parent;
  int n; // number of elements  
}; // Pts 

#endif	/* SETS_H */

