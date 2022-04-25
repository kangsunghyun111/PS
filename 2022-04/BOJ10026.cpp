#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int cnt1, cnt2;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool visited[100][100];
char grid[100][100];

void DFS(int x,int y, char c) {
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < n
			&& next_y >= 0 && next_y < n
			&& visited[next_x][next_y] == 0
			&& grid[next_x][next_y] == c) {
			visited[next_x][next_y] = 1;
			DFS(next_x,next_y,c);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			grid[i][j] = str[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				DFS(i, j, grid[i][j]);
				cnt1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			if (grid[i][j] == 'G')
				grid[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				DFS(i, j, grid[i][j]);
				cnt2++;
			}
		}
	}

	cout << cnt1 << ' ' << cnt2;

	return 0;
}