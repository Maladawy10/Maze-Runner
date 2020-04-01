#include "bestFirstSearch.h"
#include "mazeFactory.h"
#include<vector>
#include<queue>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

bestFirstSearch::bestFirstSearch()
{
	Visited = new bool[mazeFac->height*mazeFac->width + 1];
	for (int i = 1; i <= mazeFac->width*mazeFac->height; i++)
	{
		Visited[i] = 0;
	}
	parent = new int[mazeFac->height*mazeFac->width + 1];
	for (int i = 1; i <= mazeFac->width*mazeFac->height; i++)
	{
		parent[i] = 0;
	}
	lengthOfPath = 1;
	VisitedCells = 0;
	find = false;

}
int bestFirstSearch::End()
{
	int x = 0;
	for (int i = 1; i <= (mazeFac->width*mazeFac->height); i++)
		for (int j = 1; j <= (mazeFac->width*mazeFac->height); j++)
		{
			if (mazeFac->matrix[i][j] == -1) {
				x = j;
				break;
			}
		}
	return x;
}
void bestFirstSearch::Best_Firstsearch()
{
	int end = End();
	int distance = abs(mazeFac->node_map[1].first - mazeFac->node_map[end].first) + abs(mazeFac->node_map[1].second - mazeFac->node_map[end].second);
	Queue.push(make_pair(distance, 1));
	int frontNode;
	Visited[1] = true;
	VisitedCells++;
	while (true)
	{
		frontNode = Queue.top().second;
		Queue.pop();
		for (int i = 1; i <= mazeFac->width*mazeFac->height; i++)
		{
			if (mazeFac->matrix[frontNode][i] == -1)
			{

				Visited[i] = true;
				VisitedCells++;
				parent[i] = frontNode;
				find = true;
				cout << 1;
				break;
			}
			else if (mazeFac->matrix[frontNode][i] >= 1 && Visited[i] == false)
			{
				Visited[i] = true;
				VisitedCells++;
				parent[i] = frontNode;
				distance = abs(mazeFac->node_map[i].first - mazeFac->node_map[end].first) + abs(mazeFac->node_map[i].second - mazeFac->node_map[end].second);
				Queue.push(make_pair(distance, i));
			}
		}
		if (find == true) {

			break;
		}

	}

	Path.push(end);
	while (end != 1)
	{
		lengthOfPath++;
		end = parent[end];
		Path.push(end);
	}
	cout << "\t Best-firstSearch path : \n";
	while (Path.size() != 0)
	{
		cout << '(' << mazeFac->node_map[Path.top()].first << ',' << mazeFac->node_map[Path.top()].second << ')';
		if (mazeFac->mazeS[mazeFac->node_map[Path.top()].first][mazeFac->node_map[Path.top()].second] != '0')
			mazeFac->mazeS[mazeFac->node_map[Path.top()].first][mazeFac->node_map[Path.top()].second] = '.';
		Path.pop();
	}
	cout << endl;
	cout << "length of path = " << lengthOfPath - 1 << endl;
	cout << "number of cell visited = " << VisitedCells;
	for (int i = 0; i < mazeFac->x; ++i) {
		for (int j = 0; j < mazeFac->y; ++j) {
			cout << mazeFac->mazeS[i][j];
		}
	}

}



bestFirstSearch::~bestFirstSearch()
{
	delete  mazeFac;
}
