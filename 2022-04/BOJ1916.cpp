#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 1000000000

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
int dist[1001];

void dijkstra() {
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) // Same path, different cost
			continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int next_cost = adj[cur][i].second + cost;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next,next_cost });
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	int from, to, cost;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].push_back({ to,cost });
	}

	for (int i = 0; i <= 1000; i++)
		dist[i] = INF;

	int start, destination;
	cin >> start >> destination;

	dist[start] = 0;
	pq.push({ start,dist[start] });
	dijkstra();

	cout << dist[destination];

	return 0;
}
