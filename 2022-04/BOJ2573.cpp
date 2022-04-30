#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int map[300][300];
int next_map[300][300];
int visited[300][300];
int year;

void DFS(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < n
			&& next_y >= 0 && next_y < m
			&& visited[next_x][next_y] == 0
			&& map[next_x][next_y] != 0) {
			visited[next_x][next_y] = 1;
			DFS(next_x, next_y);
		}
	}
}

int CheckSea(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (map[next_x][next_y] == 0)
			cnt++;
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	

	while (1) {
		int land = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0 && visited[i][j] == 0) {
					land++;
					DFS(i, j);
				}
			}
		}

		if (land >= 2) {
			cout << year;
			break;
		}
		if (land == 0) {
			cout << 0;
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				next_map[i][j] = map[i][j] - CheckSea(i, j);
				if (next_map[i][j] < 0)
					next_map[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = next_map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				next_map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		year++;
	}


	return 0;
}