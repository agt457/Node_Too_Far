#ifndef istream_h
#define istream_h
// --------
// includes
// --------
#include <iostream> // istream, ostream
#include <string> // string
#include <utility> // pair
using namespace std;
// ------------
// collatz_read
// ------------
/**
* read two ints
* @param s a string
* @return a pair of ints, representing the beginning and end of a range, [i, j]
*/
void read_in (istream& r, ostream& w);

#endif
