#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int m, n, h;

int map[100][100][100];
int check[100][100][100];
bool visited[100][100][100];
bool checkZero;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

queue<pair<int, pair<int, int>>> q;

void BFS() {

	while (!q.empty()) {
		int z = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		visited[z][x][y] = 1;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int next_z = z + dz[i];
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_z >= 0 && next_z < h
				&& next_x >= 0 && next_x < n
				&& next_y >= 0 && next_y < m
				&& visited[next_z][next_x][next_y] == 0
				&& map[next_z][next_x][next_y] == 0) {

				q.push(make_pair(next_z, make_pair(next_x, next_y)));
				visited[next_z][next_x][next_y] = 1;
				map[next_z][next_x][next_y] = 1;
				check[next_z][next_x][next_y] = check[z][x][y] + 1;
			}
		}
	}
}

int main() {
	int temp;
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> temp;
				map[k][i][j] = temp;
				if (temp == 1) {
					q.push(make_pair(k,make_pair(i,j)));
				}
				if (temp == 0) {
					checkZero = 1;
				}
			}
		}
	}
	if (checkZero == 0) {
		cout << 0 << '\n';
		return 0;
	}
	BFS();

	int day = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[k][i][j] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (check[k][i][j] > day)
					day = check[k][i][j];
			}
		}
	}

	cout << day << '\n';

	return 0;
}