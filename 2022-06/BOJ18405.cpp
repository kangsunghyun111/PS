#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#pragma warning(disable:4996)
using namespace std;

struct Point {
	int x;
	int y;
	int virus;
	Point() {}
	Point(int X, int Y, int V) : x(X), y(Y), virus(V) {}
};

bool compare(Point a, Point b) {
	return a.virus < b.virus;
}

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int map[200][200];
int n, k, s, x, y;
vector<Point> virus;
vector<Point> virus_temp;

void increase(int x, int y, int v) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] == 0) {
				map[nx][ny] = v;
				virus_temp.push_back(Point(nx, ny, v));
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0) {
				virus.push_back(Point(i, j, map[i][j]));
			}
		}
	}
	scanf("%d %d %d", &s, &x, &y);


	for (int i = 0; i < s; i++) {
		sort(virus.begin(), virus.end(), compare);
		for (int j = 0; j < virus.size(); j++) {
			Point temp = virus[j];
			increase(temp.x, temp.y, temp.virus);
		}

		virus.clear();
		for (int k = 0; k < virus_temp.size(); k++) {
			virus.push_back(virus_temp[k]);
		}
		virus_temp.clear();
	}

	cout << map[x - 1][y - 1];

	return 0;
}