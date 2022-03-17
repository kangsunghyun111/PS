#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[100][100];
int map[100][100];
int depth[100][100];	// Distance
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
queue<pair<int, int>> q;
vector<pair<int, int>> graph[100][100];
int n, m;

void BFS(int x,int y) {
	int count = 1;
	visited[x][y] = 1;
	q.push(pair<int, int>(x, y));

	while (!q.empty()) {
		int f = q.front().first;
		int s = q.front().second;
		q.pop();

		for (int i = 0; i < graph[f][s].size(); i++) {
			int xx = graph[f][s][i].first;
			int yy = graph[f][s][i].second;

			if (visited[xx][yy] == 0) {
				visited[xx][yy] = 1;
				depth[xx][yy] = depth[f][s] + 1;
				q.push(pair<int, int>(xx, yy));
			}
		}
	}

	cout << (depth[n - 1][m - 1] + 1) << '\n';
	exit(0);
}

int main() {
	string input[100];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (input[i][j] == '1') {	// Input is string
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int xx = i + dx[k];
					int yy = j + dy[k];

					if (xx >= 0 && yy >= 0 && xx <= 99 && yy <= 99 && map[xx][yy] == 1) {
						graph[i][j].push_back(pair<int, int>(xx, yy));
					}
				}
			}
		}
	}


	BFS(0, 0);

	return 0;
}