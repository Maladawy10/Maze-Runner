#ifndef GENERATINGMAZE_H
#define GENERATINGMAZE_H
#include <iostream>
#include <stack>
#include <fstream>
using namespace std;
class Node
{

public:
    int x,y;
};
class generatingMaze
{
	ofstream maze;
    int n,m;
    int i,j,random;
    int** arr ;
    bool right,left,up,down;
    Node cell;
    public:
    void generateMaze();
    generatingMaze();
    ~generatingMaze();

};

#endif // GENERATINGMAZE_H
