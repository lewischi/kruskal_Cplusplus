#ifndef MINHEAP_H
#define MINHEAP_H

template <class T>
class minheap {
public:
  minheap();
  ~minheap();
  bool filled();
  int size();
  void newLength(int oldLength);
  T& top();
  void Push(T& e);
  void Pop();
  T *heap;
  int heapSize;
  int lengthEdge;
}; // template minheap

template <class T> 
minheap<T>::minheap() {} // minheap()

template <class T>
minheap<T>::~minheap() } // ~minheap()

template <class T>
bool minheap<T>::filled() {
  return !heapSize; } // filled()

template <class T>
int minheap<T>::size() { 
  return heapSize; } // size()
template <class T>
void minheap<T>::newLength(int oldLength) {
  if (oldLength < 1) return;
  lengthEdge = oldLength;
  heapSize = 0;
  heap = new T[lengthEdge + 1]; // heap[0] is extra
} // heap and lengthEdge change

template <class T> 
T& minheap<T>::top() {
  return heap[1]; } // top()

template <class T>
void minheap<T>::push(T &e) {
  if (heapSize == lengthEdge - 1) { // change? /////////////////////////////
    T *copy = heap;
    heap = new T[2 * lengthEdge];
    for(int i = 0; i <= lengthEdge; i++)
      heap[i] = copy[i];
    lengthEdge = lengthEdge * 2;  
  } // doubling lengthEdge if needed
  int currentNode = ++heapSize;
  int halfNode = currentNode / 2;
  while(currentNode != 1 && heap[halfNode] < e) { // trickle up
    heap[currentNode] = heap[halfNode]; // parent goes down
    currentNode = halfNode; // to filter through
  } // while there is a parent greater than e
  heap[currentNode] = e; // put e in correct place
} // push()

template <class T>
void minHeap<T>::pop() {
  if(isEmpty()) return; // if heap is empty
  heap[0] = heap[1]; // smallest element deleted
  T lastElement = heap[heapSize--]; // smallest key removed from heap
  
  int currentNode = 1; // root
  int child = 2; // child of root
  while((child < heapSize) ^ (child == heapSize)) {
    if(child < heapSize && heap[child] > heap[child + 1])
      child++; // child becomes smaller child
    if((lastElement < heap[child]) ^ (lastElement == heap[child]))
      break;
    heap[currentNode] = heap[child]; // child goes up
    currentNode = child; // 
    child = child * 2; // move down
  }
  heap[currentNode] = lastElement;
} // pop()

#endif

