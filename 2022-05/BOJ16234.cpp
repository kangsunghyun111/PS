#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

struct Point{
	int x;
	int y;
};
int n, l, r;
int map[50][50];
int map_temp[50][50];
int visited[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<Point> q;

int BFS() {
	int sum_union = 0;
	int divide = 0;
	int flag = 0;
	vector<Point> v;

	while (!q.empty()) {
		Point cur = q.front();
		sum_union += map[cur.x][cur.y];
		v.push_back(cur);
		q.pop();

		for (int i = 0; i < 4; i++) {
			Point next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < n
				&& visited[next.x][next.y] == 0) {
				int dif = abs(map[cur.x][cur.y] - map[next.x][next.y]);
				if (dif >= l && dif <= r) {
					visited[next.x][next.y] = 1;
					flag = 1;
					q.push(next);
				}
			}
		}
	}

	divide = (int)(sum_union / v.size());

	for (int i = 0; i < v.size(); i++) {
		Point temp = v[i];
		map_temp[temp.x][temp.y] = divide;
	}

	return flag;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			map_temp[i][j] = map[i][j];
		}
	}

	int count = 0;
	while (1) {
		int flag = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) {
					Point cur = Point();
					cur.x = i;
					cur.y = j;
					q.push(cur);
					visited[i][j] = 1;
					flag +=BFS();
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = map_temp[i][j];
				visited[i][j] = 0;
			}
		}

		if (flag == 0) {
			cout << count;
			break;
		}
		count++;
	}



	return 0;
}