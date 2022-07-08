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

struct Edge {
	int start;
	int end;
	int cost;
	Edge() {}
	Edge(int x, int y, int z) : start(x), end(y), cost(z) {}
};

struct compare {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

int n, m;
char gender[1001];
int parent[1001];
priority_queue<Edge, vector<Edge>, compare> pq;
int MST_cost;

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

bool isCycle(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x == y)
		return 1;
	else
		return 0;
}

void Kruskal() {
	int cnt = 0;
	while (!pq.empty()) {
		Edge temp = pq.top();
		int start = temp.start;
		int end = temp.end;
		int cost = temp.cost;
		pq.pop();

		if (isCycle(start, end) == 0) {
			unionParent(start, end);
			MST_cost += cost;
			cnt++;
		}
	}
	if (cnt < n - 1)
		cout << -1;
	else
		cout << MST_cost;
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> gender[i];
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		if (gender[start] != gender[end]) {
			pq.push(Edge(start, end, cost));
		}
	}

	Kruskal();

	return 0;
}