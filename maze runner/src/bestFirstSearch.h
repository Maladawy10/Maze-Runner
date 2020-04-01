#pragma once
#include "mazeFactory.h"
#include<vector>
#include<queue>
#include <stack>
#include <string>
using namespace std;

class bestFirstSearch
{
	mazeFactory *mazeFac=new mazeFactory;
	bool find;
	bool *Visited;
	int *parent;
	stack<int>Path;
	int lengthOfPath;
	int VisitedCells;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Queue;
public:
	bestFirstSearch();
	~bestFirstSearch();
	int End();
	void Best_Firstsearch();
};
