#ifndef MEDIAN_DATA_STRUCTURE_H
#define MEDIAN_DATA_STRUCTURE_H

#include <vector>
#include <queue> 


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
* The template allows any type, but before using it, it should be checked whether it is an arithmetic type.
*/
template <typename T>
class MedianStruct {
   private:

     //max heap to store the half of the elements, lower than the current median (left of it)
     std::priority_queue<T> maxHeap;
     //min heap to store the half of the elements, larger than the current median (right of it)
     std::priority_queue<T, std::vector<T>, std::greater<T>> minHeap;
     //the current median of the elements (can think of it as the root node of a binary tree, which has the above maxHeap as a right subtree and the minHeap as a left subtree )
     double currentMedian = 0;

   public:
      void add(T const&);  // add an element to the structure
      double getMedian() const; // get the current median

};


#endif
