/* 
 * test_sort_main.cpp
 * 
 * Author:   Makoto Shimazu <makoto.shimaz@gmail.com>
 * URL:      https://amiq11.tumblr.com               
 * License:  2-clause BSD License                    
 * Created:  2015-01-18                              
 *  
 */

#include <iostream>
#include <list>
#include <vector>

#include "gtest/gtest.h"

#include "mergesort.h"
#include "sort.h"
#include "stlsort.h"

using namespace pd;

typedef float elem_t;
typedef std::unique_ptr<Sorter<elem_t>> sorter_t;

void print_vector(const std::vector<elem_t> &data) {
  for (auto elem : data) {
    std::cout << elem << ", ";
  }
  std::cout << std::endl;
}

void exec_test(const sorter_t &sorter,
               const std::vector<elem_t> &source)
{
  std::vector<elem_t> data = source;
  print_vector(data);
  sorter->sort(data);
  print_vector(data);
}

std::vector<elem_t> exec_sort(const sorter_t &sorter,
               const std::vector<elem_t> &source)
{
  std::vector<elem_t> data = source;
  sorter->sort(data);
  return data;
}

TEST(SorterTest, MergeSort) {
  std::vector<elem_t> source_data = {2,8,9,1,7,3,4,6,5,0};
  sorter_t merge_sorter = MergeSorter<elem_t>::create();
  sorter_t stl_sorter = STLSorter<elem_t>::create();

  auto target = exec_sort(merge_sorter, source_data);
  auto expected = exec_sort(stl_sorter, source_data);

  ASSERT_EQ(expected.size(), target.size());
  for (size_t i = 0; i < expected.size(); i++)
    ASSERT_EQ(expected[i], target[i]);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
