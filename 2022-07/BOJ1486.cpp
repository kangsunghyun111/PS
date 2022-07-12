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

struct Node {
	int x;
	int y;
	int cost;
	bool operator<(const Node& d) const {
		return cost > d.cost;
	}
};

struct Mountain {
	int x;
	int y;
	int height;
	bool operator < (const Mountain& m) const {
		return height < m.height;
	}
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m, t, d;
int map[25][25];
priority_queue<Mountain> m_pq;

void Dijkstra(int start_x, int start_y) {
	priority_queue<Node> pq;
	int ans = 0;
	int dist[25][25];
	int dist_back[25][25];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INF;
			dist_back[i][j] = INF;
		}
	}
	dist[start_x][start_y] = 0;
	pq.push({ start_x,start_y,dist[start_x][start_y] });

	while (!pq.empty()) {
		Node temp = pq.top();
		int x = temp.x;
		int y = temp.y;
		int cost = temp.cost;
		pq.pop();

		if (cost >= d)
			continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next_cost = cost;
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			int diff = abs(map[nx][ny] - map[x][y]);
			if (diff <= t) {
				if (map[nx][ny] <= map[x][y]) {
					next_cost++;
					if (dist[nx][ny] > next_cost) {
						dist[nx][ny] = next_cost;
						pq.push({ nx,ny,next_cost });
					}
				}
				else {
					next_cost += diff * diff;
					if (dist[nx][ny] > next_cost) {
						dist[nx][ny] = next_cost;
						pq.push({ nx,ny,next_cost });
					}
				}
			}
		}
	}

	while (!m_pq.empty()) {
		Mountain temp = m_pq.top();
		int mx = temp.x;
		int my = temp.y;
		int height = temp.height;
		m_pq.pop();
		dist_back[mx][my] = dist[mx][my];
		pq.push({ mx,my,dist_back[mx][my] });
		while (!pq.empty()) {
			Node temp = pq.top();
			int x = temp.x;
			int y = temp.y;
			int cost = temp.cost;
			pq.pop();

			if (cost >= d)
				continue;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int next_cost = cost;

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;

				int diff = abs(map[nx][ny] - map[x][y]);
				if (diff <= t) {
					if (map[nx][ny] <= map[x][y]) {
						next_cost++;
						if (dist_back[nx][ny] > next_cost) {
							dist_back[nx][ny] = next_cost;
							pq.push({ nx,ny,next_cost });
						}
					}
					else {
						next_cost += diff * diff;
						if (dist_back[nx][ny] > next_cost) {
							dist_back[nx][ny] = next_cost;
							pq.push({ nx,ny,next_cost });
						}
					}
				}
			}
		}

		if (dist_back[0][0] <= d) {
			cout << map[mx][my];
			return;
		}
	}

	cout << ans;
	
	return;
}

int main() {
	cin >> n >> m >> t >> d;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] < 95) {
				map[i][j] = int(s[j]) - 65;
			}
			else {
				map[i][j] = int(s[j]) - 71;
			}
			m_pq.push({ i,j,map[i][j] });
		}
	}

	Dijkstra(0 ,0);

	return 0;
}