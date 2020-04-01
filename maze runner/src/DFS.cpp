#include "DFS.h"
#include <iostream>
#include <string>
using namespace std;

DFS::DFS() {

	visited = new bool[mf.height * mf.width];
	path.push(1);
	found = false;
	lengthofpath=0;
	numberOfCellVisited=0;
}
void DFS::getpath(int start) {
	visited[start] = true;
	for (int i = 1; i <= mf.height * mf.width; ++i) {
		if (mf.matrix[path.top()][i] == -1)
			found = true;
		if (mf.matrix[path.top()][i] != 0 && visited[i] == false
				&& found == false) {
		   numberOfCellVisited++;
			path.push(i);
		//	mf.mazeS[mf.node_map[path.top()].first][mf.node_map[path.top()].second] =
							'.';
			getpath(path.top());
		}

	}
	if (found == false) {
		path.pop();
	}

}
void DFS::displaypath() {
	getpath(1);
	cout<<"\tsolution by DFS"<<endl;
   	lengthofpath = path.size();
   	cout<<"Random searsh:";
	for (int i = 0; i < lengthofpath; ++i) {
		cout << '(' << mf.node_map[path.top()].first << ','
				<< mf.node_map[path.top()].second << ')' ;
		mf.mazeS[mf.node_map[path.top()].first][mf.node_map[path.top()].second] =
				'.';
		path.pop();
	}
    cout<<endl;
    cout<<"length of path = "<<lengthofpath<<endl;
    cout<<"number of cell visited = "<<numberOfCellVisited;
	for (int i = 0; i < mf.x; ++i) {
		for (int j = 0; j < mf.y; ++j) {
			cout << mf.mazeS[i][j];
		}
	}

}
DFS::~DFS() {

}
