#ifndef EDGE_H
#define	EDGE_H

#include <iostream>
using namespace std;

class Region;
class Sets;

class Edge {
  friend bool operator<(Edge* x, Edge &y);
  friend ostream & operator<<(ostream& os, const Edge& e);
  friend void kruskal();
  friend void output();

  Edge();
  ~Edge();  
  int vert1, vert2, lengthEdge;
  bool cycle, in;

  void points();
  int min();
  int max();
  bool cycleNum();
  void operator=(Edge& right);
  bool operator==(Edge& e);
  bool operator<=(Edge& e);
  bool operator>(Edge& e);
}; // class Edge

#endif	/* EDGE_H */

