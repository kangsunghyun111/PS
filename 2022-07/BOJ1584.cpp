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
	int damage;
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int map[501][501];
int visit[501][501];

void BFS() {
	deque<Point> dq;
	dq.push_back({ 0,0,0 });

	while (!dq.empty()) {
		Point temp = dq.front();
		int x = temp.x;
		int y = temp.y;
		int dmg = temp.damage;
		dq.pop_front();

		if (x == 500 && y == 500) {
			cout << dmg;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ndmg = dmg;
			if (nx < 0 || ny < 0 || nx>500 || ny>500)
				continue;
			if (visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				if (map[nx][ny] == 1) {
					ndmg++;
					dq.push_back({ nx,ny,ndmg });
				}
				else {
					dq.push_front({ nx,ny,ndmg });
				}
			}
		}
	}

	cout << "-1";
	return;
}

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 > x2) {
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if (y1 > y2) {
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				map[i][j] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 > x2) {
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if (y1 > y2) {
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				visit[i][j] = 1;
	}

	BFS();

	return 0;
}