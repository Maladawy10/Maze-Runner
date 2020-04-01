#include "Dijkstra.h"
#include <iostream>
using namespace std;

Dijkstra::Dijkstra() {
	visited = new bool[mf.height * mf.width + 1];
	for (int i = 0; i < mf.height * mf.width + 1; i++) {
		visited[i] = false;
	}
	inserted = new bool[mf.height * mf.width + 1];
	for (int i = 0; i < mf.height * mf.width + 1; i++) {
		inserted[i] = false;
	}
	parent = new int[mf.height * mf.width + 1];
	for (int i = 0; i < mf.height * mf.width + 1; i++) {
		parent[i] = 0;
	}
	final = 0;
	vertsies.insert(make_pair(0, 1));
	top = vertsies.begin();
	lengthofpath = 0;
}

void Dijkstra::makepath() {
	int cost = 1;
	bool finish = false;
	while (true) {
		finish = false;
		for (top = vertsies.begin(); top != vertsies.end(); ++top) {
			if (visited[top->second] != true) {
				finish = true;
				break;
			}
		}
		if (finish == false)
			break;
		visited[top->second] = true;
		for (int i = 1; i <= mf.height * mf.width; i++) {
			if (mf.matrix[top->second][i] == -1 && visited[i] == false) {
				final = i;
				chosefinal.push(make_pair(top->first,top->second));
				parent[i] = top->second;
			}
			if (mf.matrix[top->second][i] > 0 && visited[i] == false) {
				if (inserted[i] == true) {

					//pair<int, int> p;//p.first = top->first + cost;//p.second = i;
					for (it = vertsies.begin(); it != vertsies.end(); it++) {

						if (it->second == i) {
							if (top->first /*+ cost */ >= it->first) {

								vertsies.erase(it);
								vertsies.insert(
										make_pair((top->first + cost), i));
								//parent[i] = top->second;
								break;

							}

							break;
						}

					}

				}
				else {
					//p.first = top->first + cost; p.second = i;
					vertsies.insert(make_pair(top->first + cost, i));
					parent[i] = top->second;
					inserted[i] = true;

				}
			}
		}

	}
	parent[final]=chosefinal.top().second;

}

void Dijkstra::displaypath() {
	makepath();
	cout << "\t solution by Dijkstra" << endl;
	cout << "random search:";
	while (final != 1) {
		lengthofpath++;
		int s = parent[final];
		cout << '(' << mf.node_map[s].first << ',' << mf.node_map[s].second
				<< ')' << " ";
		mf.mazeS[mf.node_map[s].first][mf.node_map[s].second] = '.';
		final = s;
	}
	cout << endl;
	cout << "length of path = " << lengthofpath ;
	for (int i = 0; i < mf.x; ++i) {
		for (int j = 0; j < mf.y; ++j) {
			cout << mf.mazeS[i][j];
		}
	}
}

Dijkstra::~Dijkstra() {

}
