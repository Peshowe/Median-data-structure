#include "median_data_structure.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <type_traits>
#include <queue> 

using namespace std;


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


// explicit instantiations with the types this data structure can be used
//  (the linker wouldn't be able to find the template if called with a different type - wouldn't compile at all)
template class MedianStruct<int>;
template class MedianStruct<long>;
template class MedianStruct<float>;
template class MedianStruct<double>;
