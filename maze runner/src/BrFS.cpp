#include "BrFS.h"
#include "mazeFactory.h"
#include <queue>
#include <vector>
BrFS::BrFS()
{
	visited = new bool[mf.height * mf.width+1];
	parent =new int[mf.height * mf.width+1];
	path.push(1);
	find = 0;
	lengthofpath=0;
	numberOfCellVisited=0 ;
}
int BrFS::solveBrFS()
{
	int front;
	int final=1;
	while (find!=true)
	{
		front=path.front();

		for (int i = 1; i <= mf.height * mf.width; i++)
		{
			if (mf.matrix[front][i] == -1) {
				final = i;
				parent[final] = front;
				find = true;
				break;
			}
			if (mf.matrix[front][i] >= 1 &&visited[i]!=true) {
				path.push(i);
				//mf.mazeS[mf.node_map[i].first][mf.node_map[i].second] =
								'.';
				numberOfCellVisited++;
				visited[i] = true;
				parent[i] = front;

			}
		}
		path.pop();
	}
	return final;
 }
void BrFS::displaypath() {
	int final = solveBrFS();
	cout<<"\tsolution by BFS"<<endl;
	cout<<"random search:";
	while (final!=1) {
		lengthofpath++;
		int s=parent[final];
		cout << '(' << mf.node_map[s].first << ',' << mf.node_map[s].second << ')';
		mf.mazeS[mf.node_map[s].first][mf.node_map[s].second] = '.';
		final = s;
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
