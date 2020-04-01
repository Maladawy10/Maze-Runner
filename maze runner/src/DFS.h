#ifndef DFS_HEADER
#define DFS_HEADER
#include <string>
#include <stack>
#include"mazeFactory.h"
using namespace std;
class DFS {
	mazeFactory mf;
	bool *visited;
	stack<int> path;
	bool found;
	int lengthofpath;
	int numberOfCellVisited ;
public:
	void getpath(int start);
	void displaypath();
	DFS();
	~DFS();
};
#endif
