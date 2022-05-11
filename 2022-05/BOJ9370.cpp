#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
#define INF 1234567890

struct Node {
	int end;
	int cost;
	Node(int X, int Y) :end(X), cost(Y) {}
};
struct compare {
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};


vector<Node> vertex[2001];
vector<int> destination;
vector<int> Dist_S;
vector<int> Dist_G;
vector<int> Dist_H;

void Dijkstra(int n, int start, vector<int> &dist) {
	priority_queue<Node, vector<Node>, compare> pq;
	dist.assign(n + 1, INF);
	dist[start] = 0;
	pq.push(Node(start, dist[start]));

	while (!pq.empty()) {
		Node temp = pq.top();
		int cur = temp.end;
		int cost = temp.cost;
		pq.pop();

		for (int i = 0; i < vertex[cur].size(); i++) {
			temp = vertex[cur][i];
			int next = temp.end;
			int next_cost = cost + temp.cost;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push(Node(next, next_cost));
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;

		for (int i = 0; i < m; i++) {
			int start, end, cost;
			scanf("%d %d %d", &start, &end, &cost);
			vertex[start].push_back(Node(end, cost));
			vertex[end].push_back(Node(start, cost));
		}

		for (int i = 0; i < t; i++) {
			int dest;
			scanf("%d", &dest);
			destination.push_back(dest);
		}
		sort(destination.begin(), destination.end());

		Dijkstra(n, s, Dist_S);
		Dijkstra(n, g, Dist_G);
		Dijkstra(n, h, Dist_H);

		for (int i = 0; i < destination.size(); i++) {
			int Dest = destination[i];
			if (Dist_S[Dest] == Dist_S[g] + Dist_G[h] + Dist_H[Dest])
				cout << Dest << ' ';
			else if (Dist_S[Dest] == Dist_S[h] + Dist_G[h] + Dist_G[Dest])
				cout << Dest << ' ';
		}
		cout << '\n';

		for (int i = 0; i <= n; i++)
			vertex[i].clear();

		destination.clear();
		Dist_S.clear();
		Dist_G.clear();
		Dist_H.clear();
	}

	return 0;
}