#include "region.h"

using namespace std;


Region::region() : root(-1), smallest(1000000) { // isRoot
  cities = roads = 0; } // region()

Region::~region() {} // ~region()

int Region:numberCities() {
  return cities; } // numberCities()

void Region::addEdge(Edge e) {
  edge.push(e); } // addEdge()

void Region::print() {
  cout << "<region>" << endl;
  while(!edge.filled()) { // isEmpty
    cout << edge.top();
    edge.pop();
  }
  cout << "</region>" << endl;
} // print()

int Region::getRoot() {
  return root; } // getRoot()

void Region::setRoot(int x) {
  root = i; } //setRoot()

// void region::heapcap // error prevetion

bool operator<(Region& x, Region& y) {
  if(x.cities < y.cities)
    return true;
  if(x.cities == y.cities && x.smallest < y.smallest)
    return true;
  return false;
} // operator <

Region & Region::operator +=(Region& r) {
    while (!r.edge.isEmpty()) {
    edge.push(r.edge.top());
    r.edge.pop();
  } // transfer edges to this region
  cities += r.cities; // transfer cities to region
  r.cities = 0;
  if (smallest > r.smallest) // transfer smallest
    smallest = r.smallest;
  return *this;
} // operator +=
