#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int m, n;

bool visited[1000][1000];
int map[1000][1000];
int check[1000][1000];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
queue<pair<int, int>>q;

void BFS() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = 1;
		q.pop();

		int next_x;
		int next_y;

		for (int i = 0; i < 4; i++) {
			next_x = x + dx[i];
			next_y = y + dy[i];

			// If next coordinate is in the range and didn't visit
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m
				&& visited[next_x][next_y] == 0 && map[next_x][next_y] == 0) {
				visited[next_x][next_y] = 1;
				map[next_x][next_y] = 1;
				check[next_x][next_y] = check[x][y] + 1;
				q.push(pair<int, int>(next_x, next_y));
			}
		}
	}
}

int main() {
	int temp;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1)
				q.push(pair<int, int>(i, j));
		}
	}

	BFS();

	int day = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				// If map is 0, there is a unripen tomato
				cout << "-1" << '\n';
				return 0;
			}
			if (check[i][j] > day)
				day = check[i][j];
		}
	}

	cout << day << '\n';


	return 0;
}