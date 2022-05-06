#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

#define INF	123456789
typedef pair<pair<int, int>, int> edge; // start, end, cost
vector<edge> e;
vector<long long> dist;
int city[50];
int FW_adj[50][50];
int FW_dist[50][50];

bool FW(int n, int start , int end) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				FW_dist[i][j] = 0;
			else if (FW_adj[i][j] != 0)
				FW_dist[i][j] = FW_adj[i][j];
			else
				FW_dist[i][j] = INF;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				FW_dist[a][b] = min(FW_dist[a][b], FW_dist[a][k] + FW_dist[k][b]);
			}
		}
	}

	if (FW_dist[start][end] == INF)
		return 0;
	else
		return 1;
}

int main() {
	int n, from, to, m;
	cin >> n >> from >> to >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		e.push_back({ {start,end }, cost });
		FW_adj[start][end] = 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> city[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (e[i].first.second == j) {
				e[i].second -= city[j];
			}
		}
	}



	dist.assign(n, INF);
	dist[from] = -city[from];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e.size(); j++) {
			int start = e[j].first.first;
			int end = e[j].first.second;
			int cost = e[j].second;
			long long next_cost = cost + dist[start];
			if (dist[start] == INF)
				continue;
			if (dist[end] > next_cost) {
				dist[end] = next_cost;
			}
		}
	}


	int flag = 0;
	for (int i = 0; i < e.size(); i++) {
		int start = e[i].first.first;
		int end = e[i].first.second;
		int cost = e[i].second;
		long long next_cost = cost + dist[start];
		if (dist[start] == INF)
			continue;
		if (dist[end] > next_cost) {
			if (FW(n, start, to)) {
				flag = 1;
			}
		}
	}

	if (dist[to] == INF) {
		cout << "gg";
	}
	else {
		if (flag == 1) {
			cout << "Gee";
		}
		else {
			cout << -dist[to];
		}
	}

}