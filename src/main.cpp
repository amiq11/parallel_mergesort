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
#include <stdlib.h>

#include "cmdline.h"

using namespace std;

int main(int argc, const char * const argv[])
{
  cmdline::parser parser;
  parser.add("help", 'h', "print help");

  if (!parser.parse(argc, argv) || parser.exist("help")) {
    cerr << parser.error_full() << parser.usage();
    exit(EXIT_FAILURE);
  }
  cout << "Done!" << endl;
  exit(EXIT_SUCCESS);
}
