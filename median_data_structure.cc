#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <type_traits>
#include <bits/stdc++.h>

using namespace std;


/**
* Median data structure implemented as a binary tree, the root always being the current median,
* the left subtree - a max heap and the right subtree - a min heap.
* When adding an element, it is pushed to either the min or max heap, depending on whether it is larger than the current median or not.
* This means that there is an inherent overhead of O(log n), as the new value has to be "sifted", to preserve the heap.
* This overhead though is less than what would be computationaly needed to for example keep a balanced binary search tree (as we don't need to pay for that)
*   and it is also more efficient than doing an O(n) insertion sort on each add.
*
* This is an online implementation that returns the current median in O(1) time, but takes O(log n) to add.
*
* It allows any type, but before using it probably should be checked whether it is an arithmetic type.
*/
template <typename T>
class MedianStruct {
   private:

     //max heap to store the half of the elements, lower than the current median (left of it)
     priority_queue<T> maxHeap;
     //min heap to store the half of the elements, larger than the current median (right of it)
     priority_queue<T, vector<T>, greater<T>> minHeap;
     //the current median of the elements (can think of it as the root node of a binary tree, which has the above maxHeap as a right subtree and the minHeap as a left subtree )
     double currentMedian = 0;

   public:
      void add(T const&);  // add an element to the structure
      double getMedian() const; // get the current median

};


/**
* Add an element and compute the new current median
* The computation of the wanted result during each add makes this an online algorithm
*/
template <typename T>
void MedianStruct<T>::add (T const& newEl) {

  // is the new element larger than the current median
  bool isLarger = newEl > currentMedian;

  int diff = maxHeap.size() - minHeap.size(); //compute difference of the sizes of the two heaps

  //the sizes of both heaps at any time will differ by at most 1 (so signum function is implicit (in a way))
  switch (diff) {
    // maxHeap (left one) has more elements
    case 1:
      if(isLarger){
        minHeap.push(newEl); //push new element in the minHeap, as it's larger than the median
      }else{
        minHeap.push(maxHeap.top()); //push top element of the maxHeap to the minHeap
        maxHeap.pop(); // and pop that element to make space for the new element
        maxHeap.push(newEl); //push new element to the maxHeap
      }

      //now both heaps are the same size, so calculate median by taking the average of the tops of both heaps
      currentMedian = (double)(maxHeap.top() + minHeap.top())/2;
      break;

    // both heaps are equal size
    case 0:
      if(isLarger){
        minHeap.push(newEl); //push new element to the minHeap
        currentMedian = minHeap.top(); //the new currentMedian is now the top of the minHeap, since it is now bigger in size than the maxHeap
      }else{
        maxHeap.push(newEl);
        currentMedian = maxHeap.top();
      }
      break;

    // minHeap (right one) has more elements
    case -1:
      if(isLarger){
        maxHeap.push(minHeap.top()); //make space for new element by moving the top of the minHeap to the maxHeap
        minHeap.pop();
        minHeap.push(newEl); //push new element
      }else{
        maxHeap.push(newEl);
      }

      //now both heaps are the same size, so calculate median by taking the average of the tops of both heaps
      currentMedian = (double)(maxHeap.top() + minHeap.top())/2;
      break;
  }

  cout<<currentMedian<<endl;

}


/**
* Return the current median of the elements in the data structure
*/
template <typename T>
double MedianStruct<T>::getMedian () const {

  //throw an exception if the data structure is empty (median is undefined)
  if(maxHeap.empty() && minHeap.empty()){
    throw out_of_range("MedianStruct<>::calcMedian(): no elements in the data structure");
  }

  return currentMedian;
}

int main() {
   try {

      int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
      MedianStruct<int> intStruct;
      for(int a: A) intStruct.add(a);

      cout << intStruct.getMedian() <<endl;

   } catch (exception const& ex) {
      cerr << "Exception: " << ex.what() <<endl;
      return -1;
   }
}
