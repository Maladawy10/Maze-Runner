
#ifndef ASTAR_H_
#define ASTAR_H_
#include "mazeFactory.h"
#include<vector>
#include<queue>
#include <stack>
#include <string>
using namespace std;
class Astar {

	mazeFactory mazeFac;
		bool find;
		bool *Visited;
		int *parent;
		stack<int>Path;
		int *cost;
		int lengthOfPath;
		int VisitedCells;
		priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> Queue;
public:
		int End();
		void displaypath();

	Astar();
	virtual ~Astar();
};

#endif
