#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 100000000

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int lab[8][8];
int temp[8][8];

queue<pair<int, int>> q;
vector<pair<int, int>> q_temp;
vector<pair<int, int>> blank;
int n,m;

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n
				&& next_y >= 0 && next_y < m
				&& temp[next_x][next_y] == 0) {
				temp[next_x][next_y] = temp[x][y] + 1;
				q.push({ next_x,next_y });
			}
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
			temp[i][j] = lab[i][j];
			if (lab[i][j] == 2) {
				q.push({ i,j });
				q_temp.push_back({ i,j });
			}
			if (lab[i][j] == 0)
				blank.push_back({ i,j });
		}
	}


	int max = 0;
	for (int i = 0; i < blank.size(); i++) {
		for (int j = 0; j < blank.size(); j++) {
			for (int k = 0; k < blank.size(); k++) {
				if (i == j || j == k || k == i)
					continue;
				if (i > j || j > k)
					continue;
				int a_x, a_y, b_x, b_y, c_x, c_y;
				a_x = blank[i].first;
				a_y = blank[i].second;
				b_x = blank[j].first;
				b_y = blank[j].second;
				c_x = blank[k].first;
				c_y = blank[k].second;

				temp[a_x][a_y] = 1;
				temp[b_x][b_y] = 1;
				temp[c_x][c_y] = 1;

				for (int v = 0; v < q_temp.size(); v++) {
					q.push({ q_temp[v].first,q_temp[v].second });
				}

				BFS();

				int cnt = 0;
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < m; b++) {
						if (temp[a][b] == 0)
							cnt++;
						
						temp[a][b] = lab[a][b];
					}
				}

				if (max < cnt)
					max = cnt;
			}
		}
	}

	cout << max;

	return 0;
}