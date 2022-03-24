#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m;
int N, M;
int map[1000][1000];
bool visited[2][1000][1000];
int check[2][1000][1000];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<pair<int, int>, int>> q;

void BFS() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int numDestroy = q.front().second;
		visited[numDestroy][x][y] = 1;
		q.pop();

		if (x == N && y == M) {
			cout << check[numDestroy][x][y] + 1;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < n
				&& next_y >= 0 && next_y < m) {
				// If next step is wall and can destroy wall
				if (map[next_x][next_y] == 1 && numDestroy) {
					q.push({ {next_x,next_y},0 });
					check[numDestroy-1][next_x][next_y] = check[numDestroy][x][y] + 1;
					visited[numDestroy-1][next_x][next_y] = 1;
				}
				// If next step is not wall and didn't visit
				else if (map[next_x][next_y] == 0 && visited[numDestroy][next_x][next_y]==0) {
					q.push({ {next_x,next_y},numDestroy });
					check[numDestroy][next_x][next_y] = check[numDestroy][x][y] + 1;
					visited[numDestroy][next_x][next_y] = 1;
				}
			}
		}
	}


	cout << -1;
}
int main() {
	cin >> n>> m;
	N = n - 1;
	M = m - 1;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '1') {
				map[i][j] = 1;
			}
		}
	}


	q.push(make_pair(make_pair(0, 0), 1));
	BFS();


	return 0;
}