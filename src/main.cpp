/* 
 * main.cpp
 * 
 * Author:   Makoto Shimazu <makoto.shimaz@gmail.com>
 * URL:      https://amiq11.tumblr.com
 * License:  2-clause BSD (see LICENSE)
 * Created:  2015-01-18
 *  
 */

#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>

#include "cmdline.h"
#include "stlsort.h"

using namespace pd;

typedef float elem_t;

void print_vector(const std::vector<elem_t> &data) {
  for (auto elem : data) {
    std::cout << elem << ", ";
  }
  std::cout << std::endl;
}

int main(int argc, const char * const argv[]) {
  cmdline::parser parser;
  parser.add("help", 'h', "print help");

  if (!parser.parse(argc, argv) || parser.exist("help")) {
    std::cerr << parser.error_full() << parser.usage();
    exit(EXIT_FAILURE);
  }

  std::vector<elem_t> data = {0.5, 1.0, 0.1, 0.6};

  auto sorter = STLSorter<elem_t>::create();

  print_vector(data);
  sorter->sort(data);
  print_vector(data);

  std::cout << "Done!" << std::endl;
  exit(EXIT_SUCCESS);
}
