#include "edge.h"

using namespace std;


Edge::Edge() : cycle(false), in(false) {
  vert2 = vert1 = lengthEdge = -1;
} // Edge()

Edge::~Edge() { } // ~Edge()

void Edge::points() {
  cin >> vert1 >> vert2 >> lengthEdge;
  if(vert1 > vert2) {
    int temp = vert1;
    vert1 = vert2;
    vert2 = temp;
  } // if wrong order, switch
} // points()

int Edge::min() {
  if(vert1 < vert2)
    return vert1;
  else
    return vert2;
} // min()

int Edge::max() {
  if(vert1 > vert2)
    return vert1;
  else
    return vert2;
} // max()

bool Edge::cycleNum() {
  return cycle;
} // cycleNum()

void Edge::operator=(Edge& right) {
  lengthEdge = right.lengthEdge;
  vert1 = right.vert1;
  vert2 = right.vert2;
} // operator =

bool Edge::operator==(Edge& e) {
  if(lengthEdge == e.lengthEdge && min() == e.min() && max() == e.max())
    return true;
  else
    return false;
} // operator ==

bool Edge::operator>(Edge& e) {
  if(lengthEdge > e.lengthEdge)
    return true;
  if(lengthEdge == e.lengthEdge) {
    if(min() > e.min())
      return true;
    if(min() == e.min() && max() > e.max())
      return true;
  }
  return false;
} // operator >

ostream & operator<<(ostream& os, Edge& e) {
  cout << "roads: hi alan: " << e.min;
//   CHECK THIS
}


/*
bool selfLoop(const Edge& e) {
  return e.vertex1 == e.vertex2;
} // isValid()
*/
