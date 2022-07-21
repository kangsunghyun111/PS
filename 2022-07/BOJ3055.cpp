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

#define INF 2100000000
#define LLINF 9223372036854775800

struct Point {
	int x;
	int y;
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int map[50][50];
int visit[50][50];
int dist_water[50][50];
int dist_hedgehog[50][50];

int R, C;
vector<Point> water;
Point hog;
Point dest;

void BFS_water() {
	queue<Point> q;
	for (int i = 0; i < water.size(); i++) {
		Point t = water[i];
		q.push(t);
		visit[t.x][t.y] = 1;
	}

	while (!q.empty()) {
		Point temp = q.front();
		int x = temp.x;
		int y = temp.y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>=R || ny>=C)
				continue;

			if (visit[nx][ny] == 0 && map[nx][ny] == 0) {
				visit[nx][ny] = 1;
				dist_water[nx][ny] = dist_water[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

void BFS_hedgehog() {
	queue<Point> q;
	visit[hog.x][hog.y] = 1;
	q.push(hog);

	while (!q.empty()) {
		Point temp = q.front();
		int x = temp.x;
		int y = temp.y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;

			if (visit[nx][ny] == 0 && map[nx][ny] == 0) {
				visit[nx][ny] = 1;
				dist_hedgehog[nx][ny] = dist_hedgehog[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '.') {
				map[i][j] = 0;
				continue;
			}
			if (s[j] == 'X') {
				map[i][j] = 1;
				continue;
			}
			if (s[j] == '*') {
				map[i][j] = 2;
				water.push_back({ i,j });
				continue;
			}
			if (s[j] == 'S') {
				map[i][j] = 8;
				hog = { i,j };
				continue;
			}
			if (s[j] == 'D') {
				map[i][j] = 9;
				dest = { i,j };
				continue;
			}
		}
	}

	BFS_water();

	memset(visit, 0, sizeof(visit));

	BFS_hedgehog();

	int ans = INF;
	
	for (int i = 0; i < 4; i++) {
		int nx = dest.x + dx[i];
		int ny = dest.y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			continue;

		if (map[nx][ny] == 8) {
			ans = 0;
			break;
		}

		if (dist_hedgehog[nx][ny] < dist_water[nx][ny]) {
			if (dist_hedgehog[nx][ny] == 0)
				continue;
			if (ans > dist_hedgehog[nx][ny]) {
				ans = dist_hedgehog[nx][ny];
			}
		}
		else if (dist_hedgehog[nx][ny] !=0 && dist_water[nx][ny] == 0) {
			if (ans > dist_hedgehog[nx][ny]) {
				ans = dist_hedgehog[nx][ny];
			}
		}
	}

	if (ans == INF)
		cout << "KAKTUS";
	else
		cout << ans + 1;


	return 0;
}