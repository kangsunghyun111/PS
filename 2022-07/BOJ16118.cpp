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
	int turn;
};

struct compare {
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

int n, m;
vector<Node> v[4001];

int Dijkstra(int dest) {
	priority_queue < Node, vector<Node>, compare> pq;
	vector<int> dist_fox;
	dist_fox.assign(n + 1, INF);
	dist_fox[1] = 0;
	pq.push({ 1,dist_fox[1],0 });

	while (!pq.empty()) {
		Node temp = pq.top();
		int cur = temp.end;
		int cost = temp.cost;
		int turn = temp.turn;
		pq.pop();

		if (dist_fox[cur] < cost)
			continue;

		for (int i = 0; i < v[cur].size(); i++) {
			temp = v[cur][i];
			int next = temp.end;
			int next_cost = cost + temp.cost * 2;
			int next_turn = turn + 1;
			if (dist_fox[next] > next_cost) {
				dist_fox[next] = next_cost;
				pq.push({ next,next_cost,next_turn });
			}
		}
	}


	vector<int> dist_wolf[2];
	dist_wolf[0].assign(n + 1, INF);
	dist_wolf[1].assign(n + 1, INF);
	dist_wolf[0][1] = 0;
	pq.push({ 1,dist_wolf[0][1],0});

	while (!pq.empty()) {
		Node temp = pq.top();
		int cur = temp.end;
		int cost = temp.cost;
		int turn = temp.turn;
		pq.pop();

		if (dist_wolf[turn%2][cur] < cost)
			continue;

		for (int i = 0; i < v[cur].size(); i++) {
			temp = v[cur][i];
			int next = temp.end;
			int next_cost = temp.cost;
			int next_turn = turn + 1;

			if (turn % 2 == 0) {
				next_cost = cost + next_cost;
				if (dist_wolf[1][next] > next_cost) {
					dist_wolf[1][next] = next_cost;
					pq.push({ next,next_cost,next_turn });
				}
			}
			else {
				next_cost = cost + next_cost * 4;
				if (dist_wolf[0][next] > next_cost) {
					dist_wolf[0][next] = next_cost;
					pq.push({ next,next_cost,next_turn });
				}
			}
		}
	}

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (dist_fox[i] < min(dist_wolf[0][i],dist_wolf[1][i]))
			ans++;
	}

	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		v[start].push_back({ end,cost,0 });
		v[end].push_back({ start,cost,0 });
	}

	int ans = Dijkstra(n);

	cout << ans;

	return 0;
}