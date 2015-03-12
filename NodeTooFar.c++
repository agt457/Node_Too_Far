#include <iostream> // endl, istream, ostream
#include <sstream> // istringstream
#include <map> 
#include <utility> // make_pair, pair
#include <vector>
#include <queue>

#include "NodeTooFar.h"

using namespace std;

/*int count_nodes (istream& r, int nc){
	map<int, bool> exists;
	int count = 0;
	while(nc > 0){
		int first;
		int second;
		r >> first >> second;
		//cout << "first: " << first << " second: " << second << endl;

		if(exists.count(first) == 0){
                        ++count;
			//cout << "f" << endl;
                        exists[first] = true;
                }

                if(exists.count(second) == 0){
                        ++count;
			//cout << "s" << endl;
                        exists[second] = true;
                }

		--nc;
	}

	return count;
}*/

int reachable(int start, int ttl, map<int, vector<int>> network){
	int res = 0;
	map<int, bool> seen;

	queue<int> q;
	seen[start] = true;
	++res;
	q.push(start);

	while(ttl > 0){
		queue<int> next_level;
		while(!q.empty()){
		int node = q.front();
		q.pop();

		vector<int> connect = network[node];
		for(int x = 0 ; x < connect.size(); x++){
			int next = connect[x];
			if(seen.count(next) == 0){
				seen[next] = true;
				++res;
				next_level.push(next);	
			}
		}
		}
		--ttl;
		q = next_level;	
	}

	return res;
}


	/*if(ttl == 0)
		return 1;

	seen[start] = true;
	
	vector<int> node = network[start];
	for(int x = 0; x < node.size(); ++x){
		int check = node[x];
		if(seen.count(check) == 0)
			return 1 + reachable(check, --ttl, network, seen);
	}
}*/

map<int, vector<int>> make_net (istream& r, int nc){
	map<int, vector<int>> network;
	while(nc > 0){
		int first;
		int second;
		r >> first >> second;
		
		if(network.count(first) == 0){
			vector<int> a;
			a.push_back(second);
			network[first] = a;
					}
		else{
			//cout << "hey "<< first << " ";
			vector<int>& a = network[first];
			a.push_back(second);				
			}		
		//vector<int>::iterator i1 = a.end();

		if(network.count(second) == 0){
			vector<int> b;
			b.push_back(first);
			network[second] = b;
					}
		else{
                        vector<int>& b = network[second];
			b.push_back(first);	
				}
		//vector<int>::iterator i2 = b.end();

		--nc;
	}

		//if(network.begin() == network.end())
		//	cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
		
		return network;		
}

void node_solve (istream& r, ostream& w){
	int cas = 1;
	int nc;
	r >> nc;
	while(nc > 0){
		map<int, vector<int>> network = make_net(r, nc);
		int start;
		int ttl;
		r >> start >> ttl;
		while(start != 0 || ttl > 0){
			int count = reachable(start, ttl, network);
			int cant_reach = network.size() - count;
			w << "Case " << cas << ": " << cant_reach << " nodes not reachable from node " << start << " with TTL = " << ttl << ".";
			w << endl;
			++cas;
			r >> start >> ttl;	
		}
		r >> nc;
	}
}

int main () {
    using namespace std;
    node_solve(cin, cout);
    return 0;}		
