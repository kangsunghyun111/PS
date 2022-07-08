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
int parent[200000];
int total_cost = 0;
int MST_cost = 0;
priority_queue<Edge, vector<Edge>, compare> pq;

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	if (xp < yp) {
		parent[yp] = parent[xp];
	}
	else {
		parent[xp] = parent[yp];
	}
}

bool isCycle(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	if (xp == yp) {
		return 1;
	}
	else {
		return 0;
	}
}

void Kruskal() {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	while (!pq.empty()) {
		Edge temp = pq.top();
		int start = temp.start;
		int end = temp.end;
		int cost = temp.cost;
		pq.pop();

		if (isCycle(start, end) == 0) {
			unionParent(start, end);
			MST_cost += cost;
		}
	}
}

int main() {
	while (1) {	
		cin >> n >> m;
		if (n + m == 0) {
			break;
		}

		for (int i = 0; i < m; i++) {
			int start, end, cost;
			scanf("%d %d %d", &start, &end, &cost);

			pq.push(Edge(start, end, cost));		
			total_cost += cost;
		}

		Kruskal();
		cout << total_cost - MST_cost << "\n";
		total_cost = 0;
		MST_cost = 0;
	}

	return 0;
}