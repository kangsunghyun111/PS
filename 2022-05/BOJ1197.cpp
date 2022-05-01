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
vector<node> vertex[10001];
vector<int> dist;
int selected[10001];
int visited[10001];

int v, e;
long long MST_cost;

void Prim() {
	for (int i = 1; i <= v; i++) {
		int cur = 0;
		int min_dist = INF;
		for (int j = 1; j <= v; j++) {
			if (selected[j] == 0 && min_dist > dist[j]) {
				min_dist = dist[j];
				cur = j;
			}
		}

		MST_cost += min_dist;
		selected[cur] = 1;

		for (int j = 0; j < vertex[cur].size(); j++) {
			int next = vertex[cur][j].first;
			int cost = vertex[cur][j].second;

			if (selected[next] == 0 && dist[next] > cost)
				dist[next] = cost;
		}
	}
}

void Prim_heap() {
	priority_queue<node, vector<node>, compare> pq;
	for (int i = 0; i <vertex[1].size(); i++) {
		int next = vertex[1][i].first;
		int cost = vertex[1][i].second;
		pq.push({ next,cost });
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

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int start, to, cost;
		scanf("%d %d %d", &start, &to, &cost);
		vertex[start].push_back({ to,cost });
		vertex[to].push_back({ start,cost });
	}

	dist.assign(v + 1, INF);
	dist[1] = 0;
	//Prim();
	Prim_heap();
	cout << MST_cost;

	return 0;
}