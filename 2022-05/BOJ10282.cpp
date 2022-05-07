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
typedef pair<int, int> node; // end, cost
struct compare {
	bool operator()(node a, node b) {
		return a.second > b.second;
	}
};

vector<node> vertex[10001];
vector<long long> dist;

void Dijkstra(int n,int c) {
	priority_queue<node, vector<node>, compare> pq;		
	dist.assign(n + 1, INF);
	dist[c] = 0;
	pq.push({ c,dist[c] });

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)
			continue;
		for (int i = 0; i < vertex[cur].size(); i++) {
			int next = vertex[cur][i].first;
			int next_cost = cost + vertex[cur][i].second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next,next_cost });
			}
		}
	}

	int cnt = 0;
	int time = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			if (time < dist[i])
				time = dist[i];
			cnt++;
		}
	}

	cout << cnt << " " << time << '\n';
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, d, c;
		cin >> n >> d >> c;
		
		for (int i = 0; i < d; i++) {
			int start, end, cost;
			scanf("%d %d %d", &end, &start, &cost);
			vertex[start].push_back({ end,cost });
		}

		Dijkstra(n, c);
		
		for (int i = 1; i <= n; i++) {
			vertex[i].clear();
		}
	}
}