/* 
 * stlsort.h
 * 
 * Author:   Makoto Shimazu <makoto.shimaz@gmail.com>
 * URL:      https://amiq11.tumblr.com               
 * License:  MIT License                             
 * Created:  2015-02-04                                  
 *  
 */

#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "sort.h"

namespace pd {

template <class Element>
class STLSorter : public Sorter<Element> {
public:
  void sort(std::vector<Element>& data) const override {
    std::sort(data.begin(), data.end());
  }

  static std::unique_ptr<STLSorter> create() {
    return std::unique_ptr<STLSorter>(new STLSorter<Element>());
  }
private:
  STLSorter() {}
};

};
