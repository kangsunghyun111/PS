#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
#define INF 1234567890

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map[500][500];
int dp[500][500];
int n;

int dfs(int x, int y) {
	if (dp[x][y] != 0)
		return dp[x][y];

	dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n
			&& map[x][y] < map[next_x][next_y]) {

			dp[x][y] = max(dp[x][y], dfs(next_x, next_y)+1);
		}
	}
	return dp[x][y];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = dfs(i, j);
			if (max < temp)
				max = temp;
		}
	}

	cout << max;
}