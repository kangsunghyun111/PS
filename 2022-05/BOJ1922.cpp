#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define INF	2147483647
typedef pair<int, int> node; // end, cost
struct compare {
	bool operator()(node a, node b) {
		return a.second > b.second;
	}
};

int n, m;
vector<node> vertex[1001];
vector<long long> dist;
int selected[1001];	// Prim
int visited[1001]; // Prim_heap
long long MST_cost;

void Prim() {
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		int min_dist = INF;
		for (int j = 1; j <= n; j++) {
			if (selected[j] == 0 && min_dist > dist[j]) {
				min_dist = dist[j];
				cur = j;
			}
		}

		MST_cost += min_dist;
		selected[cur] = 1;

		for (int j = 0; j < vertex[cur].size(); j++) {
			int next = vertex[cur][j].first;
			int next_cost = vertex[cur][j].second;

			if (selected[next] == 0 && dist[next] > next_cost) {
				dist[next] = next_cost;
			}
		}
	}
}

void Prim_heap() {
	priority_queue<node, vector<node>, compare> pq;
	for (int i = 0; i < vertex[1].size(); i++) {
		int next = vertex[1][i].first;
		int next_cost = vertex[1][i].second;
		pq.push({ next,next_cost });
	}
	visited[1] = 1;

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (visited[cur] == 0) {
			visited[cur] = 1;
			MST_cost += cost;

			for (int i = 0; i < vertex[cur].size(); i++) {
				int next = vertex[cur][i].first;
				int next_cost = vertex[cur][i].second;
				if (visited[next] == 0) {
					pq.push({ next,next_cost });
				}
			}
		}
	}
}

int parent[1001]; // Kruskal
typedef pair<pair<int, int>, int> edge;
struct compare_kruskal {
	bool operator()(edge a, edge b) {
		return a.second > b.second;
	}
};

priority_queue<edge, vector<edge>, compare_kruskal> e;

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	int x_parent = findParent(x);
	int y_parent = findParent(y);
	if (x_parent < y_parent)
		parent[y_parent] = x_parent;
	else
		parent[x_parent] = y_parent;
}

bool isCycle(int x, int y) {
	int x_parent = findParent(x);
	int y_parent = findParent(y);
	if (x_parent == y_parent)
		return 1;
	else
		return 0;
}

void Kruskal() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (!e.empty()) {
		int start = e.top().first.first;
		int end = e.top().first.second;
		int cost = e.top().second;
		e.pop();

		if (isCycle(start, end) == 0) {
			unionParent(start, end);
			MST_cost += cost;
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		vertex[start].push_back({ end,cost });
		vertex[end].push_back({ start,cost });
		e.push({ {start,end},cost });
	}

	//dist.assign(n + 1, INF);
	//[1] = 0;
	//Prim();
	//Prim_heap();
	Kruskal();
	cout << MST_cost;
}