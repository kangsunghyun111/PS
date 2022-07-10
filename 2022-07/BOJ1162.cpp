#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

#define INF 9223372036854775800

typedef long long ll;

struct Node {
	int end;
	ll cost;
	int paved;
};

struct compare {
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

int n, m, k;
vector<Node> v[10001];
vector<ll> dist[21];

void Dijkstra() {
	priority_queue<Node, vector<Node>, compare> pq;
	for (int i = 0; i < 21; i++) {
		dist[i].assign(n + 1, INF);
		dist[i][1] = 0;
	}
	pq.push({ 1,dist[0][1],0 });

	while (!pq.empty()) {
		Node temp = pq.top();
		int cur = temp.end;
		ll cost = temp.cost;
		int paved = temp.paved;
		pq.pop();
		if (dist[paved][cur] < cost)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			temp = v[cur][i];
			int next = temp.end;
			ll next_cost = cost + temp.cost;		

			if (dist[paved][next] > next_cost) {
				dist[paved][next] = next_cost;
				pq.push({ next,next_cost, paved });
			}

			if (paved < k) {
				next_cost = cost + 0;
				paved++;
				if (dist[paved][next] > next_cost) {
					dist[paved][next] = next_cost;
					pq.push({ next,next_cost,paved });
				}
				paved--;
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		v[start].push_back({ end,cost });
		v[end].push_back({ start,cost });
	}

	Dijkstra();

	ll min_cost = INF;
	for (int i = 0; i <= k; i++) {
		if (min_cost > dist[i][n])
			min_cost = dist[i][n];
	}
	cout << min_cost;

	return 0;
}