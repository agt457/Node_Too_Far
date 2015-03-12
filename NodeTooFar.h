#ifndef Node_h
#define Node_h
// --------
// includes
// --------
#include <iostream> // istream, ostream
#include <sstream> // string
#include <utility> // pair
#include <map>
#include <vector>
#include <queue> 

using namespace std;

//int count_nodes(istream& r, int nc);

int reachable(int start, int ttl, map<int, vector<int>> network);

map<int, vector<int>> make_net(istream& r, int nc);

void node_solve (istream& r, ostream& w);

#endif
