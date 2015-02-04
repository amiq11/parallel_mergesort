/* 
 * sort.h
 * 
 * Author:   Makoto Shimazu <makoto.shimaz@gmail.com>
 * URL:      https://amiq11.tumblr.com               
 * License:  MIT License                             
 * Created:  2015-02-04                                  
 *  
 */

#pragma once

#include <vector>

namespace pd {

template <class Element>
class Sorter {
public:
  virtual void sort(std::vector<Element> &data) const = 0;
};

};
