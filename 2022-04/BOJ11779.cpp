#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321
typedef pair<int, int> node; // end, cost
struct compare {
	bool operator()(node a, node b) {
		return a.second > b.second;
	}
};

int n, m;
int from, to;
vector<node> v[1001];
priority_queue<node, vector<node>, compare> pq;
vector<long long> dist;
int path_temp[1001];

void Dijkstra() {
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_cost = cost + v[cur][i].second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				path_temp[next] = cur;
				pq.push({ next,next_cost });
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		v[start].push_back({ end,cost });
	}
	cin >> from >> to;
	dist.assign(n + 1, INF);
	dist[from] = 0;
	pq.push({ from,dist[from] });
	Dijkstra();

	vector<int> path;
	int iter = to;
	path.push_back(iter);
	while (1) {
		if (iter == from)
			break;

		path.push_back(path_temp[iter]);
		iter = path_temp[iter];
	}

	cout << dist[to] << '\n';
	cout << path.size() << '\n';
	for (int i = path.size() - 1; i >= 0; i--)
		printf("%d ", path[i]);

	return 0;
}