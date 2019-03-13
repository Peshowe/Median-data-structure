#include "median_data_structure.h"
#include <iostream>

using namespace std;

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
