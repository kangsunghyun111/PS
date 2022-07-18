#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdio.h> 
#pragma warning(disable:4996)

using namespace std;

#define INF 1000000000
#define LLINF 9223372036854775800


int dx[2][6] = { {-1,-1,0,1,1,0}, { -1,-1,0,1,1,0 } };
int dy[2][6] = { {-1,0,1,0,-1,-1}, { 0,1,1,1,0,-1 } };

int W, H;
int map[102][102];
int visit[102][102];
int ans = 0;

struct Point {
	int x;
	int y;
};

void BFS0(int a, int b) {
	queue<Point> q;
	visit[a][b] = 1;
	q.push({ a,b });
	while (!q.empty()) {
		Point temp = q.front();
		int x = temp.x;
		int y = temp.y;
		int flag;
		q.pop();

		if (x % 2 == 0)
			flag = 0;
		else
			flag = 1;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[flag][i];
			int ny = y + dy[flag][i];

			if (nx<0 || ny<0 || nx>H+1 || ny>W+1)
				continue;

			if (map[nx][ny] == 0 && visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void BFS1(int a, int b) {
	queue<Point> q;
	visit[a][b] = 1;
	q.push({ a,b });
	while (!q.empty()) {
		Point temp = q.front();
		int x = temp.x;
		int y = temp.y;
		int flag;
		q.pop();

		if (x % 2 == 0)
			flag = 0;
		else
			flag = 1;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[flag][i];
			int ny = y + dy[flag][i];
			
			if (nx<0 || ny<0 || nx>H + 1 || ny>W + 1)
				continue;

			if (map[nx][ny] == 0 && visit[nx][ny] == 1) {
				ans++;
				continue;
			}

			if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}


int main() {
	cin >> W >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int flag = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] == 0) {
				BFS0(i, j);
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0)
				BFS1(i, j);
		}
	}

	cout << ans;

	return 0;
}