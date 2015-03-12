#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream

#include "gtest/gtest.h"

#include "istream.h"

using namespace std;

TEST(istream, read_i) {
istringstream r("1 10\n100 200\n201 210\n900 1000\n");
ostringstream w;
read_in (r, w);
ASSERT_EQ("1 10 100 200 201 210 900 1000 ", w.str());}
