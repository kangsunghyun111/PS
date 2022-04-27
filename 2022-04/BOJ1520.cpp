#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n;
int map[500][500];
int dp[500][500];

int DFS(int x, int y) {
	if (x == m-1 && y == n-1) {
		return 1;
	}
	else if (dp[x][y] == -1) {
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < m
				&& next_y >= 0 && next_y < n) {
				if (map[x][y] > map[next_x][next_y]) {
					dp[x][y] += DFS(next_x, next_y);
				}
			}
		}
	}

	return dp[x][y];
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++)
			dp[i][j] = -1;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}


	DFS(0, 0);
	cout << dp[0][0];

	return 0;
}