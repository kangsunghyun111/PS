#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
int cave[125][125];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
vector<pair<int,int>> node[15625];
vector<int> dist;
vector<int> ans;


void Dijkstra() {
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i].first;
			int next_cost = cost + node[cur][i].second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next,next_cost });
			}
		}
	}
}

int main() {
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &cave[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 4; k++) {
					int next_x = i + dx[k];
					int next_y = j + dy[k];
					if (next_x >= 0 && next_x < n
						&& next_y >= 0 && next_y < n) {
						int start = n * i + j;
						int end = n * next_x + next_y;
						int cost = cave[next_x][next_y];
						node[start].push_back({ end,cost });
					}
				}
			}
		}


		dist.assign(n * n, INF);
		dist[0] = cave[0][0];
		pq.push({ 0,dist[0] });
		Dijkstra();

		ans.push_back(dist[n * n - 1]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				node[n * i + j].clear();
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << "Problem " << i + 1 << ": " << ans[i] << '\n';
	}

	return 0;
}