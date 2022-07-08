#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

#define INF 1000000000

struct Node {
	int end;
	int cost;
	Node(){}
	Node(int x, int y) :end(x), cost(y) {}
};

struct compare {
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

int n, m;
vector<Node> v[201];
priority_queue<Node, vector<Node>, compare> pq;
vector<int> dist;
vector<int> path;
int ans[201][201];

void Dijkstra(int start) {
	dist.assign(201, INF);
	path.assign(201, 0);
	dist[start] = 0;
	pq.push(Node(start, dist[start]));

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
				pq.push(Node(next, next_cost));

				path[next] = cur;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		ans[i][start] = path[i];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		v[start].push_back(Node(end, cost));
		v[end].push_back(Node(start, cost));
	}

	for (int i = 1; i <= n; i++) {
		Dijkstra(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j] == 0)
				cout << '-' << ' ';
			else
				cout << ans[i][j] << ' ';
		}
		cout << "\n";
	}

	return 0;
}