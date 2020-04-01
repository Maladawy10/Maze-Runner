#pragma once
#ifndef BRFS_HEADER
#define BRFS_HEADER
#include "mazeFactory.h"
#include<vector>
#include<queue>
#include <stack>
class BrFS
{
	queue<int>path;
	bool *visited;
	bool find;
	mazeFactory mf;
	int* parent;
	int lengthofpath;
	int numberOfCellVisited ;
public:
	BrFS();
	int solveBrFS();
	void displaypath();
};
#endif
