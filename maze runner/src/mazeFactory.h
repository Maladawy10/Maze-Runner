#ifndef MAZEFACTORY_HEADER
#define MAZEFACTORY_HEADER
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class mazeFactory {
	int distance;
	int calcdistance(int cellnumber);
	void adjacentmatrix();
	void createnodemap();
	int mm;
	int finalX,finalY;
    ifstream maze;
public:
	int width,height;
	map<int, pair<int, int>> node_map;
	unordered_map<int,vector<int>> matrix;
	int x,y;
	char ** mazeS;
   	 mazeFactory();
	 ~mazeFactory();
};
#endif
