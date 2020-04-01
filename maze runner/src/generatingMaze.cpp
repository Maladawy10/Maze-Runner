#include "generatingMaze.h"
#include <iostream>
#include <stack>
using namespace std;

generatingMaze::generatingMaze() {
	m=0;
	n=0;
	i = 1;
	j = 1;
	right = left = up = down = true;
	maze.open("maze.text");
}

void generatingMaze::generateMaze() {

	cout << "Enter the length and width" << endl;
	cin >> m >> n;
	maze<<m<<' '<<n<<endl;
	n = (n * 2) + 1;
	m = (m * 2) + 1;
	arr = new int*[n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			arr[x][y] = 0;
		}
	}

	arr[i][j] = 1;
	cell.x = i;
	cell.y = j;
	stack<Node> path;
	path.push(cell);

	while (true) {
		random = rand() % 4;
		if (right == false && left == false && up == false && down == false) {

			path.pop();
			if (!path.empty()) {

				i = path.top().x;
				j = path.top().y;
				right = left = down = up = true;
			} else
				break;

		}

		if (random == 0) {
			j += 2;
			if (j < 0 || j > m - 1 || i < 0 || i > n - 1) {
				down = false;
				j -= 2;
				continue;

			} else if ((arr[i][j] != 0 || arr[i][j - 1] != 0)
					|| (down == false)) {
				down = false;
				j -= 2;
				continue;
			}

			else {
				arr[i][j - 1] = 1;
				arr[i][j] = 1;
				cell.x = i;
				cell.y = j;
				path.push(cell);
				right = down = left = up = true;

			}
		}

		if (random == 1) {
			j -= 2;
			if (j < 0 || j > m - 1 || i < 0 || i > n - 1) {
				up = false;
				j += 2;
				continue;
			} else if ((arr[i][j] != 0 || arr[i][j + 1] != 0)
					|| (up == false)) {
				up = false;
				j += 2;
				continue;
			}

			else {
				arr[i][j + 1] = 1;
				arr[i][j] = 1;
				cell.x = i;
				cell.y = j;
				path.push(cell);
				right = down = left = up = true;

			}

		}

		if (random == 2) {
			i += 2;
			if (j < 0 || j > m - 1 || i < 0 || i > n - 1) {
				right = false;
				i -= 2;
				continue;
			} else if ((arr[i][j] != 0 || arr[i - 1][j] != 0)
					|| (right == false)) {
				right = false;
				i -= 2;
				continue;
			}

			else {
				arr[i - 1][j] = 1;
				arr[i][j] = 1;
				cell.x = i;
				cell.y = j;
				path.push(cell);
				right = down = left = up = true;

			}
		}

		if (random == 3) {
			i -= 2;
			if (j < 0 || j > m - 1 || i < 0 || i > n - 1) {
				left = false;
				i += 2;
				continue;
			}
			if ((arr[i][j] != 0 || arr[i + 1][j] != 0) || (left == false)) {
				left = false;
				i += 2;
				continue;
			}

			else {
				arr[i + 1][j] = 1;
				arr[i][j] = 1;
				cell.x = i;
				cell.y = j;
				path.push(cell);
				right = down = left = up = true;

			}

		}

	}

	int mm = 0;
	int nn = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if(x==1&&y==1){
				cout <<'*';
								maze <<'*';
			}
		else if(x==n-2&&y==m-2){
							cout<<'0';
							maze <<'0';
			} else if (arr[x][y] == 0 && mm % 2 == 0&&nn%2!=0) {
				cout << '|';
				maze << '|';

			} else if (arr[x][y] == 0 && mm % 2 == 0) {
				mm++;
				cout << '+';
				maze << '+';
			} else if (arr[x][y] == 0) {
				mm++;
				cout << '-';
				maze << '-';
			} else {

				cout << " ";
				maze << " ";
			}


		}
				nn++;
		cout << endl;
		maze << endl;

	}
	maze.close();
}
generatingMaze::~generatingMaze() {
	delete[] arr;
}
