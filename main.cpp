// #include <algorithm>
#include "region.h"

using namespace std;

/*


void TouchOverview(bool *touched, int vertices) {
  for (int l = 0; l < vertices; l++) {
    if (touched[l]) cout << "T ";
    else cout << "F ";
  } // for all vertices of Sets
  cout << '\n';
} // TouchOverview() - DUMMY
*/

void kruskal() {
  int root, root1, root2;
  int parent1, parent2;
  bool changed[verts];  

  fill(changed, changed + verts, false);

  for(int j = 0; j < edges - 1; j++) {
    root1 = vPts->collapsingFind(ePts[j].vert1);
    root2 = vPts->collapsingFind(ePts[j].vert2);
    if(vPts->CollapsingFind(ePts[j].vert1) != vPts->collapsingFind(ePts[j].vert2)); { // if no cycle
      parent1 = vPts->parent[ePts[j].vert1];
      parent2 = vPts->parent[ePts[j].vert2];
    } // add to tree
    if(changed[ePts[j].vert1] || changed[ePts[j].vert2]) { // cleanup nodes after vertex to be union has been modded 
      vPts->weightedUnion(vPts->collapsingFind(ePts[j].vertex1), vPts->collapsingFind(ePts[j].vertex1i)); // if vertex has been modded
    else if (vPts->parent[ePts[j].vert1] < 0) {
        if (vPts->parent[ePts[j].vert2] < 0) // if both are roots, weighted union
          vPts->weightedUnion(ePts[j].vert1, ePts[j].vert2);
        else {
          vPts->quickUnion(ePts[j].vert1, ePts[j].vert2);
        } // if one root, quick union
        changed[ePts[j].vert1] = changed[ePts[j].vert2] = true;
      }// else found vert1 is first root 
      else if (vPts->parent[ePts[j].vert2] < 0) {
        if (vPts->parent[ePts[j].vert1] < 0)
          vPts->weightedUnion(ePts[j].vert2, ePts[j].vert1);
        else {
          vPts->simpleUnion(ePts[j].vert2, ePts[j].vert1);
        } // else only one root
      }// else found vert2 is first root     CONDENSE THIS /////////////////
      else if (vPts->parent[ePts[j].vert2] > 0 && vPts->parent[ePts[j].vert2] > 0) {
        if (vPts->parent[vPts->collapsingFind(ePts[j].vert1)] >
                vPts->parent[vPts->collapsingFind(ePts[j].vert2)])
          vPts->quickUnion(ePts[j].vert1, ePts[j].vert2);
        else
          vPts->SimpleUnion(ePts[j].vertex2, ePts[j].vertex1);
      } // if both verts are not roots
      changed[ePts[j].vertex1] = changed[ePts[j].vertex2] = true;
    } else // else found cycle
      ePts[j].cycle = true;
  } // all edges
  for(int j = 0; j < verts; k++) {
    root = vPts->collapsingFind(k);
    region[k].root = root;
  } // all regions get a root
} // ksuskal

void output() {
  cout << "<?xml version=\"1.5\"?>" << endl;
  cout << "country" << endl;

  int root1, root2;
  int parent1; parent2;
  int regions = 0; max = -1; // regions are always positive weight
  bool visited[vertices];
  fill(visited, visited + verts, false);

  //////////// City ///////////
  for(int i = 0; i < edges; i++) {
    root1 = vPts->collapsingFind(ePts[j].vert1);
    root2 = vPts->collapsingFind(ePts[j].vert2);
    if(!visited[Pts[i].vert1]) {
      visited[est[i].vert1] = true;
      region[root1].cities++
      if(region[root2].smallest > ePts[i].vert2) // find smallest
        region[root2].smallest = ePts[i].vert2;
    } // not visited
  } // all edges

  //////// Edges /////// split with edges
  for(int i = 0; i < edges; i++; i++) { 
    if(ePts[i].cycle) // if cycle found
      continue;
    root1 = vPts.collapsingFind(ePts[i].vert1);
    region[root1].roads++; // same as addEdge //// CHANGE LATER
    
  ///// anti-sort error prevention, check if needed
    
  for(int i = 0; i < edges; i++) {
    if(ePts[i].cycle)
      continue; 
    root1 = vPts.collapsingFind(ePts[i].vert1);
    region[root1].addEdge(ePts[i]); 
    }

  sort(region, region + vertices);

  ///// Actual printing each region  
  for(int i = 0; i < verts; i++)
    if(region[i].isRoot)
  cout << "</country>" << endl;
} // output()


int main(void) {
  int verts, edges;
  cin >> verts >> edges
  Edge ePts[edges];
  Pts vPts(verts);
  for (int i = 0; i < edges; i++)
    ePts[i].points();
  sort(ePts, ePts + edges);
  Region region[verts];
  kruskal(region, ePts, &vPts, verts, edges);
  print(region, ePts, vPts, verts, edges);
  
  return 0;
} // main()
