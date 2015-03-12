#include <iostream> // endl, istream, ostream
#include <sstream> // istringstream

#include "istream.h"

using namespace std;

void read_in (istream& r, ostream& w) {
	int in;
	while(r >> in){
		w << in << " ";
	}
}
