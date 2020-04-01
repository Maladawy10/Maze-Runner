#include "mazeFactory.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
mazeFactory::mazeFactory() {
	mm=0;
	finalX=0;
	finalY=0;
	distance=0;
	width = 0;
	height = 0;

	maze.open("maze.text");
	if (maze.is_open()) {

		maze >> width >> height;

		y = width * 2 + 2;
		x = height * 2 + 1;

		mazeS = new char*[x];
		for (int i = 0; i < x; i++) {
			mazeS[i] = new char[y];
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				maze.get(mazeS[i][j]);
				if(mazeS[i][j]=='0'){
					finalX=i;
					finalY=j;
				}
			}

		}

		maze.close();
	}

	else {
		cout << "file (maze.text) can not open\n";
	}
     createnodemap();
     adjacentmatrix();
}
void mazeFactory::createnodemap(){

	mm = 1;
		for (int i = 2; i < y - 1; i += 2) {
			for (int j = 1; j < x - 1; j += 2) {
				node_map[mm] = make_pair(j, i);
				mm++;
			}

		}
}
int mazeFactory::calcdistance(int cellnumber){
	return abs( node_map[cellnumber].first-finalX)+abs( node_map[cellnumber].second-finalY);

}
void mazeFactory::adjacentmatrix(){
	mm = 1;
		vector<int> vec((height * width) + 1);

		for (int i = 2; i < y - 1; i += 2) {
			for (int j = 1; j < x - 1; j += 2) {
				if (mazeS[j + 1][i] == ' ') {
					vec[mm + 1] = 1;//calcdistance(mm+1);
					if (mazeS[j + 2][i] == '0')
						vec[mm + 1] = -1;
				}
				if (mazeS[j - 1][i] == ' ') {
					vec[mm - 1] = 1;//calcdistance(mm-1);
					if (mazeS[j - 2][i] == '0')
						vec[mm - 1] = -1;
				}
				if (mazeS[j][i + 1] == ' ') {
					vec[mm + height] =1;// calcdistance(mm+height);
					if (mazeS[j][i + 2] == '0')
						vec[mm + height] = -1;
				}
				if (mazeS[j][i - 1] == ' ') {
					vec[mm - height] =1;// calcdistance(mm-height);
					if (mazeS[j][i - 2] == '0')
						vec[mm - height] = -1;
				}

				matrix[mm] = vec;
				//fill(vec.begin(),vec.end(),0);
				memset(&vec[0], 0, vec.size() * sizeof vec[0]);
				mm++;
			}
		}


}

mazeFactory::~mazeFactory() {

}
