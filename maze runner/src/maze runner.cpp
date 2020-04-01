#include <iostream>
#include "mazeFactory.h"
#include "DFS.h"
#include "BrFS.h"
#include "generatingMaze.h"
#include "Dijkstra.h"
#include <set>
#include "bestFirstSearch.h"
#include "Astar.h"

using namespace std;
int main() {

	generatingMaze gm;
	    gm.generateMaze();

	DFS df;
	df.displaypath();
	cout<<"\n------------------------------------------------------------------------------------------------------------------\n";
	BrFS bf;
	bf.displaypath();
	cout<<"\n------------------------------------------------------------------------------------------------------------------\n";
	Dijkstra dj;
	dj.displaypath();
	cout<<"\n------------------------------------------------------------------------------------------------------------------\n";
	bestFirstSearch bs;
    bs.Best_Firstsearch();
	cout<<"\n------------------------------------------------------------------------------------------------------------------\n";
	Astar a;
	a.displaypath();
}

