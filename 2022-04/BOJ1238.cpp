#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 100000000

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

vector<pair<int, int>> adj[1001];
priority_queue < pair<int, int>, vector<pair<int, int>>, compare> pq;
vector<int> dist[1001];

void dijkstra(int n) {
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int next_cost = cost + adj[cur][i].second;
			if (dist[n][next] > next_cost) {
				dist[n][next] = next_cost;
				pq.push({ next,next_cost });
			}
		}
	}
}

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	
	int start, end, cost;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &end, &cost);
		adj[start].push_back({ end,cost });
	}

	for (int i = 1; i <= n; i++) {
		dist[i].assign(n + 1, INF);
	}

	// Calculate the shortest path from X node to other nodes
	dist[x][x] = 0;
	pq.push({ x,dist[x][x] });
	dijkstra(x);


	int max = 0;
	int temp;
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		pq.push({ i,dist[i][i] });
		dijkstra(i);
		temp = dist[i][x] + dist[x][i];
		if (max < temp)
			max = temp;
	}

	cout << max;

	return 0;
}