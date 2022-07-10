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
#define LLINF 9223372036854775800

struct Node {
	int end;
	int cost;
};

struct compare {
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

int n, m, r;
int item[101];
vector<Node> v[101];

int Dijkstra(int start) {
	priority_queue<Node, vector<Node>, compare> pq;
	vector<int> dist;
	dist.assign(n + 1, INF);
	dist[start] = 0;
	pq.push({ start,dist[start] });

	while (!pq.empty()) {
		Node temp = pq.top();
		int cur = temp.end;
		int cost = temp.cost;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < v[cur].size(); i++) {
			temp = v[cur][i];
			int next = temp.end;
			int next_cost = cost + temp.cost;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next,next_cost });
			}
		}
	}

	int item_num = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] <= m) {
			item_num += item[i];
		}
	}

	return item_num;
}

int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &item[i]);
	}
	for (int i = 0; i < r; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		v[start].push_back({ end,cost });
		v[end].push_back({ start,cost });
	}

	int max_item = 0;
	for (int i = 1; i <= n; i++) {
		int t = Dijkstra(i);
		if (max_item < t)
			max_item = t;
	}

	cout << max_item;

	return 0;
}