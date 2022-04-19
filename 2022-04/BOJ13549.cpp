#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 100001

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int n, k;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

void Dijkstra() {
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		for (int i = 0; i < 3; i++) {
			int next, next_cost;
			if (i == 0) {
				next = cur - 1;
				next_cost = cost + 1;
			}
			if (i == 1) {
				next = cur + 1;
				next_cost = cost + 1;
			}
			if (i == 2) {
				next = cur * 2;
				next_cost = cost;
			}

			if (next >= 0 && next <= 100000) {
				if (dist[next] > next_cost) {
					dist[next] = next_cost;
					pq.push({ next,next_cost });
				}
			}
		}
	}
}

int main() {
	cin >> n >> k;
	dist.assign(100001, INF);

	dist[n] = 0;
	pq.push({ n,dist[n] });

	Dijkstra();

	cout << dist[k];

	return 0;
}