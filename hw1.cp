#include <iostream>
#include <time.h>
#include <stack>

using namespace std;
char **RandomMaze(int row, int col, char **maze);
void Escape(int row, int col, char **maze);
void print(char **maze, int row, int col);


int main()
{

	int row = 0, col = 0;

	cout << "Please input m and n to make a mxn maze.\n";
	cin >> row >> col;
	char **maze = new char*[row + 2];
	for (int i = 0; i < row + 2; i++) {
		maze[i] = new char[col + 2];
	}

	Escape(row, col, RandomMaze(row, col, maze));

	if (maze[row][col] != '!') {
		cout << "There is no path to Exit in this maze!" << endl;
	}

	for (int i = 0; i < row + 2; i++) {
		delete[] maze[i];
	}
	delete[] maze;
	system("pause");
	return 0;
}

char **RandomMaze(int row, int col, char **maze)
{

	srand(time(NULL));
	for (int i = 0; i < row + 2; i++) {
		for (int j = 0; j < col + 2; j++) {
			if (i == 0 || i == row + 1 || j == 0 || j == col + 1) {
				maze[i][j] = '1';
			}
			else
				maze[i][j] = (rand() % 2) + '0';
		}
	}
	maze[1][1] = '0';

	print(maze, row, col);

	/*for (int i = 0; i < row + 2; i++) {
		for (int j = 0; j < col + 2; j++) {
		cout << maze[i][j];
		}
		cout << endl;
		}*/
	return maze;
}

void Escape(int row, int col, char **maze)
{
	stack<int> record;
	int x = 1, y = 1;
	maze[1][1] = '!';
	while (/*maze[row][col] == '0' || maze[row][col] == '1'*/maze[row][col] != '!') {

		if (maze[x + 1][y + 1] == '0') {
			maze[x + 1][y + 1] = '!';
			x++, y++;
			record.push(135);
		}
		else if (maze[x + 1][y] == '0') {
			maze[x + 1][y] = '!';
			x++;
			record.push(180);
		}
		else if (maze[x][y + 1] == '0') {
			maze[x][y + 1] = '!';
			y++;
			record.push(90);
		}
		else if (maze[x + 1][y - 1] == '0') {
			maze[x + 1][y - 1] = '!';
			x++, y--;
			record.push(225);
		}
		else if (maze[x][y - 1] == '0') {
			maze[x][y - 1] = '!';
			y--;
			record.push(270);
		}
		else if (maze[x - 1][y + 1] == '0') {
			maze[x - 1][y + 1] = '!';
			x--, y++;
			record.push(45);
		}
		else if (maze[x - 1][y] == '0') {
			maze[x - 1][y] = '!';
			x--;
			record.push(360);
		}
		else if (maze[x - 1][y - 1] == '0') {
			maze[x - 1][y - 1] = '!';
			x--, y--;
			record.push(315);
		}

		else if (record.empty()) {
			break;
		}
		/*else if (record.top() == '360') {
			x++;
			record.pop();
			}
			else if (record.top() == '45') {
			x++, y--;
			record.pop();
			}
			else if (record.top() == '90') {
			y--;
			record.pop();
			}
			else if (record.top() == '135') {
			x--, y--;
			record.pop();
			}
			else if (record.top() == '180') {
			x--;
			record.pop();
			}
			else if (record.top() == '225') {
			x--, y++;
			record.pop();
			}
			else if (record.top() == '270') {
			y++;
			record.pop();
			}
			else if (record.top() == '315') {
			x++, y++;
			record.pop();
			}*/
		else {
			switch (record.top()) {
			case 360:
				x++;
				record.pop();
				break;
			case 45:
				x++, y--;
				record.pop();
				break;
			case 90:
				y--;
				record.pop();
				break;
			case 135:
				x--, y--;
				record.pop();
				break;
			case 180:
				x--;
				record.pop();
				break;
			case 225:
				x--, y++;
				record.pop();
				break;
			case 270:
				y++;
				record.pop();
				break;
			case 315:
				x++, y++;
				record.pop();
				break;
			}
		}
	}

	print(maze, row, col);

}

void print(char **maze, int row, int col)
{

	for (int i = 0; i < row + 2; i++) {
		for (int j = 0; j < col + 2; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;

}