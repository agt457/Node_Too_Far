#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <map>
#include <utility>
#include <vector>
#include <queue>

#include "gtest/gtest.h"

#include "NodeTooFar.h"

using namespace std;

TEST(NodeTooFar, check_1) {
	istringstream r("1 10\n100 200\n201 210\n900 10\n");
	map<int, vector<int>> w = make_net(r, 4);
	ASSERT_EQ(7, w.size());
}

TEST(NodeTooFar, check_2) {
        istringstream r("1 10\n1 20\n20 10\n30 20\n");
        map<int, vector<int>> w = make_net(r, 4);
        ASSERT_EQ(4, w.size());
}

TEST(NodeTooFar, make_1) {
        istringstream r("1 10\n1 20\n1 30\n30 20\n 30 10");
        ostringstream bleh;
	map<int, vector<int>> w = make_net(r, 5);

	map<int, vector<int>>::iterator it = w.begin();
	vector<int> t = it->second;
	//1cout << "AAAAAAAAAAAA " << t[10]<< endl;

	//if(w.begin() == w.end())
		//cout << "whahahhwh";
	for (map<int, vector<int>>::iterator it = w.begin(); it != w.end(); it++)
	{
    		bleh << it->first << ": ";  // string (key)
		vector<int> t = it->second;   // string's value
		//cout << "SIZZEE: " << t.size() << endl; 
		for(int x = 0; x<t.size(); x++){
			bleh << t[x] << " ";
			//cout << "0 I bet: " << x << endl;
		}
	}

        ASSERT_EQ("a", bleh.str());
}

TEST(NodeTooFar, count_1) {
        istringstream r("10 15 15 20 20 25 10 30 30 47 47 50 25 45 45 65\n15 35 35 55 20 40 50 55 35 40 55 60 40 60 60 65");
        map<int, vector<int>> test_net = make_net(r, 16);
	int count = reachable(35, 2, test_net);
	ASSERT_EQ(8, count);
}

TEST(NodeTooFar, solve_1) {
        istringstream r("16\n10 15 15 20 20 25 10 30 30 47 47 50 25 45 45 65\n15 35 35 55 20 40 50 55 35 40 55 60 40 60 60 65\n35 2 35 3 0 0\n\n14\n 1 2 2 7 1 3 3 4 3 5 5 10 5 11\n 4 6 7 6 7 8 7 9 8 9 8 6 6 11\n1 1 1 2 3 2 3 3 0 0\n\n0");
	ostringstream bleh;
      
	node_solve(r, bleh);
        ASSERT_EQ("", bleh.str());
}


