#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

#define INF 1000000000
#define LLINF 9223372036854775800

struct Point {
	int x;
	int y;
	int destroy;
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int n, m, k;
int map[1000][1000];
int visit[11][1000][1000];
int check[1000][1000];
queue<Point> q;

void BFS() {
	while (!q.empty()) {
		Point temp = q.front();
		int x = temp.x;
		int y = temp.y;
		int destroy_num = temp.destroy;
		q.pop();

		if (x == n - 1 && y == m - 1)
			break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nd = destroy_num;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (map[nx][ny] == 0) {

			}
			else if (map[nx][ny] == 1) {
				nd++;
				if (nd > k)
					continue;
			}

			if (visit[nd][nx][ny] == 0) {
				visit[nd][nx][ny] = 1;
				check[nx][ny] = check[x][y] + 1;
				q.push({ nx,ny,nd });
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	q.push({ 0,0,0 });
	visit[0][0][0] = 1;
	check[0][0] = 1;
	BFS();

	if (check[n - 1][m - 1] == 0)
		cout << -1;
	else
		cout << check[n - 1][m - 1];

	return 0;
}