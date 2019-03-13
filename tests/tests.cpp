#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "median_data_structure.h"

/**
* A few test cases written using the doctest framework for C++ 
*/

TEST_CASE("testing the data structure with ints") {

  SUBCASE("check that the structure returns the correct median after an odd set of sorted inputs has been inserted") {
      int int_array[] = {5,6,7,8,9,10,11};
      MedianStruct<int> intStruct;
      for(int a: int_array) intStruct.add(a);

      CHECK(intStruct.getMedian() == 8);
    }

    SUBCASE("check that the structure returns the correct median after an even set of sorted inputs has been inserted") {
      int int_array[] = {5,6,7,8,9,10,11,12};
      MedianStruct<int> intStruct;
      for(int a: int_array) intStruct.add(a);

      CHECK(intStruct.getMedian() == 8.5);
    }

    SUBCASE("check that the structure returns the correct median after an odd set of unsorted inputs has been inserted") {
      int int_array[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4, 4};
      MedianStruct<int> intStruct;
      for(int a: int_array) intStruct.add(a);

      CHECK(intStruct.getMedian() == 6);
    }

    SUBCASE("check that the structure returns the correct median after an even set of unsorted inputs has been inserted") {
      int int_array[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
      MedianStruct<int> intStruct;
      for(int a: int_array) intStruct.add(a);

      CHECK(intStruct.getMedian() == 6.5);
    }

    SUBCASE("check that the structure returns the correct current median after each add") {
      MedianStruct<int> intStruct;
      intStruct.add(4);
      CHECK(intStruct.getMedian() == 4);
      intStruct.add(2);
      CHECK(intStruct.getMedian() == 3);
      intStruct.add(5);
      CHECK(intStruct.getMedian() == 4);
      intStruct.add(3);
      CHECK(intStruct.getMedian() == 3.5);
      intStruct.add(6);
      CHECK(intStruct.getMedian() == 4);
    }


    SUBCASE("check that the structure returns the correct median of a set of equal inputs") {
      int int_array[] = {2,2,2,2,2,2,2,2,2,2};
      MedianStruct<int> intStruct;
      for(int a: int_array) intStruct.add(a);

      CHECK(intStruct.getMedian() == 2);
    }
}


TEST_CASE("testing the data structure with doubles") {
  double double_array[] = {1.65,10.43,43.32,12.23,54.32,21.23,4.32,6.1233,41.321,53.123};
  MedianStruct<double> doubleStruct;
  for(double a: double_array) doubleStruct.add(a);

  CHECK(doubleStruct.getMedian() == 16.73);
}

TEST_CASE("testing that an exception is thrown if an attempt to access the median is made, when structure is empty") {
  MedianStruct<long> emptyStruct;
  CHECK_THROWS_AS(emptyStruct.getMedian(), std::exception);
}
