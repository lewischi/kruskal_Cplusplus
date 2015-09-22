#ifndef REGION_H
#define	REGION_H

#include "minheap.h"

class Region {
  friend bool operator<(Region &x, Region &b);
  friend void kruskal(Region *region, Edge *ePts, Pts *vPts);
  friend void output(Region *region, Edge *ePts, Pts vPts, int verts, int edges);

  Region();
  ~Region();
  Region & operator +=(Region& r);
  int numberCities();
  void addEdge(Edge e);
  void print();
  int getRoot();
  void setRoot(int x);
//  void SetHeapCap(int x); error prevention
  minheap<Edge> edge; // store all edges in region
  int cities, root, roads, smallest;
//  bool isRoot;
}; // region class

#include "edge.h"
#include "sets.h"

#endif	/* REGION_H */

