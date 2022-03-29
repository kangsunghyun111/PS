#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int board[9][9];
vector<pair<int, int>> v;

bool isPromising(int x,int y) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == board[x][y] && i != y)
			return false;
		if (board[i][y] == board[x][y] && i != x)
			return false;
	}

	int tx = x / 3;
	int ty = y / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x == tx * 3 + i && y == ty * 3 + j)
				continue;

			if ((board[i + tx * 3][j + ty * 3] == board[x][y]))
				return false;
		}
	}

	return true;
}

void sudoku(int level) {
	if (level == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
		return;
	}

	int x = v[level].first;
	int y = v[level].second;

	for (int i = 0; i < 9; i++) {
		board[x][y] = i + 1;
		if (isPromising(x, y)) {
			sudoku(level + 1);
			
		}
		board[x][y] = 0;
	}
}

int main() {
	int temp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> temp;
			board[i][j] = temp;
			if (temp == 0) {
				v.push_back({ i,j });
			}
		}
	}

	sudoku(0);

	return 0;
}