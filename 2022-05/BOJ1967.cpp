#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

#define INF	2147483647
typedef pair<int, int> node; // end, cost
struct compare{	
	bool operator()(node a, node b) {
		return a.second > b.second;
	}
};

int n;
vector<node> vertex[10001];
vector<long long> dist;

void Dijkstra(int V, int D) {
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ V, D });

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < vertex[cur].size(); i++) {
			int next = vertex[cur][i].first;
			int next_cost = cost+vertex[cur][i].second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next,next_cost });
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		vertex[start].push_back({ end,cost });
		vertex[end].push_back({ start,cost });
	}

	dist.assign(n + 1, INF);
	dist[1] = 0;
	Dijkstra(1,dist[1]);

	int longest = 0;
	int longest_node = 0;
	for (int i = 1; i <= n; i++) {
		if (longest < dist[i]) {
			longest = dist[i];
			longest_node = i;
		}
	}

	dist.assign(n + 1, INF);
	dist[longest_node] = 0;
	Dijkstra(longest_node, dist[longest_node]);

	for (int i = 1; i <= n; i++) {
		if (longest < dist[i]) {
			longest = dist[i];
			longest_node = i;
		}
	}
	if (n == 1)
		cout << 0;
	else
		cout << longest;
	
	return 0;
}