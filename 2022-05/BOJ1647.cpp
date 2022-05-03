#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define INF	2147483647
typedef pair<pair<int, int>, int> edge;
typedef pair<int, int> node;
struct compare {
	bool operator()(edge a, edge b) {
		return a.second > b.second;
	}
};
struct compare_prim {
	bool operator()(node a, node b) {
		return a.second > b.second;
	}
};

int n, m;
priority_queue<edge, vector<edge>, compare> pq;
int parent[100001];
int MST_cost;
vector<int> temp_cost;

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	int x_p = findParent(x);
	int y_p = findParent(y);
	if (x_p < y_p)
		parent[y_p] = parent[x_p];
	else
		parent[x_p] = parent[y_p];
}

bool isCycle(int x, int y) {
	int x_p = findParent(x);
	int y_p = findParent(y);
	if (x_p == y_p)
		return 1;
	else
		return 0;
}

void Kruskal() {
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	while (!pq.empty()) {
		int start = pq.top().first.first;
		int end = pq.top().first.second;
		int cost = pq.top().second;
		pq.pop();

		if (isCycle(start, end) == 0) {
			unionParent(start, end);
			MST_cost += cost;
			temp_cost.push_back(cost);
		}
	}
}

int visited[100001];
vector<node> vertex[100001];
priority_queue<node, vector<node>, compare_prim> pq_prim;

void Prim_heap() {
	visited[1] = 1;
	for (int i = 0; i < vertex[1].size(); i++) {
		int next = vertex[1][i].first;
		int cost = vertex[1][i].second;
		pq_prim.push({ next,cost });
	}

	while (!pq_prim.empty()) {
		int cur = pq_prim.top().first;
		int cost = pq_prim.top().second;
		pq_prim.pop();

		if (visited[cur] == 0) {
			visited[cur] = 1;
			MST_cost += cost;
			temp_cost.push_back(cost);

			for (int i = 0; i < vertex[cur].size(); i++) {
				int next = vertex[cur][i].first;
				int next_cost = vertex[cur][i].second;
				if(visited[next]==0)
					pq_prim.push({ next,next_cost });
			}
		}
	}
	
	int max = 0;
	for (int i = 0; i < temp_cost.size(); i++)
		if (max < temp_cost[i])
			max = temp_cost[i];

	cout << MST_cost - max;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		vertex[start].push_back({ end,cost });
		vertex[end].push_back({ start,cost });
		pq.push({ {start,end},cost });
	}

	//Kruskal();
	//cout << MST_cost - temp_cost.back();
	Prim_heap();

	return 0;
}