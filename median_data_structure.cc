#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <type_traits>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class MedianStruct {
   private:

     //max heap to store the half of the elements, lower than the current median (left of it)
     priority_queue<T> maxHeap;
     //min heap to store the half of the elements, larger than the current median (right of it)
     priority_queue<T, vector<T>, greater<T>> minHeap;
     //the current median of the elements (can think of it as the root node of a binary tree, which has the above maxHeap as a right subtree and the minHeap as a left subtree )
     double currentMedian = 0;

     // void swapAndPush(priority_queue<T>*, priority_queue<T>*, T const&);

   public:
      void add(T const&);  // add an element to the structure
      double getMedian() const; // get the current median

};

// template <typename T>
// void swapAndPush(priority_queue<T>* smallerHeap, priority_queue<T>* biggerHeap, T const& newEl){
//     *smallerHeap.push(*biggerHeap.top()); //push top element of the bigger heap to the smaller heap
//     *biggerHeap.pop(); // and pop that element to make space for the new element
//     *smallerHeap.push(newEl); //push new element to the smaller heap
// }


/**
* Add an element and compute current median (online algorithm)
*/
template <typename T>
void MedianStruct<T>::add (T const& newEl) {

  // is the new element larger than the current median
  bool isLarger = newEl > currentMedian;

  int diff = maxHeap.size() - minHeap.size(); //compute difference of the sizes of the two heaps
  // int sgn = (T(0) < diff) - (diff < T(0)); //get the sign of the difference (signum function)

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
        // swapAndPush(&minHeap, &maxHeap, newEl);
      }

      //now both heaps are the same size, so calculate median by taking the average of the tops of both heaps
      currentMedian = (double)(maxHeap.top() + minHeap.top())/2;

    // both heaps are equal size
    case 0:
      if(isLarger){
        minHeap.push(newEl); //push new element to the minHeap
        currentMedian = minHeap.top(); //the new currentMedian is now the top of the minHeap, since it is now bigger in size than the maxHeap
      }else{
        maxHeap.push(newEl);
        currentMedian = maxHeap.top();
      }

    // minHeap (right one) has more elements
    case -1:
      if(isLarger){
        maxHeap.push(minHeap.top()); //make space for new element
        minHeap.pop();
        minHeap.push(newEl);
        // swapAndPush(&maxHeap, &minHeap, newEl);
      }else{
        maxHeap.push(newEl);
      }

      //now both heaps are the same size, so calculate median by taking the average of the tops of both heaps
      currentMedian = (double)(maxHeap.top() + minHeap.top())/2;

  }
}

template <typename T>
double MedianStruct<T>::getMedian () const {

  // if(elements.empty()){
  //   throw out_of_range("MedianStruct<>::calcMedian(): no elements in the data structure");
  // }

  // return copy of last element
  return currentMedian;
}

int main() {
   try {
      MedianStruct<int> intStruct;

      // manipulate int stack
      intStruct.add(5);
      intStruct.add(10);
      intStruct.add(20);
      cout << intStruct.getMedian() <<endl;


      // // manipulate string stack
      // Stack<string> stringStack;    // stack of strings
      // stringStack.push("hello");
      // cout << stringStack.top() << std::endl;
      // stringStack.pop();
      // stringStack.pop();
   } catch (exception const& ex) {
      cerr << "Exception: " << ex.what() <<endl;
      return -1;
   }
}
