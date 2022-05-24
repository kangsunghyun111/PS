#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
#define INF 2000000000
struct Edge {
	int start;
	int end;
	int cost;
	Edge(){}
	Edge(int X, int Y, int Z) : start(X), end(Y), cost(Z) {}
};
struct Node {
	int end;
	int cost;
	Node() {}
	Node(int X, int Y) : end(X), cost(Y) {}
};
struct compare {
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

int n, m;
vector<Edge> edges;
vector<long long> dist;
int prev_node[101];
vector<int> path;

vector<Node> v[101];

bool Dijkstra(int n, int start, int end) {
	priority_queue<Node, vector<Node>, compare> pq;
	vector<long long> d;
	d.assign(n + 1, INF);
	d[start] = 0;
	pq.push(Node(start, d[start]));

	while (!pq.empty()) {
		Node temp = pq.top();
		int cur = temp.end;
		int cost = temp.cost;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			temp = v[cur][i];
			int next = temp.end;
			long long next_cost = cost + temp.cost;
			if (d[next] > next_cost) {
				d[next] = next_cost;
				pq.push(Node(next, next_cost));
			}
		}
	}

	if (d[end] == INF)
		return 0;
	else
		return 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		edges.push_back(Edge(start, end, -cost));
		v[start].push_back(Node(end, 1));
	}

	dist.assign(101, INF);
	dist[1] = 0;

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < edges.size(); j++) {
			Edge temp = edges[j];
			int start = temp.start;
			int end = temp.end;
			int cost = temp.cost;
			long long next_cost = cost + dist[start];
			if (dist[start] == INF)
				continue;
			if (dist[end] > next_cost) {
				dist[end] = next_cost;
				prev_node[end] = start;
			}
		}
	}

	int flag = 0;
	for (int i = 0; i < edges.size(); i++) {
		Edge temp = edges[i];
		int start = temp.start;
		int end = temp.end;
		int cost = temp.cost;
		long long next_cost = cost + dist[start];
		if (dist[start] == INF)
			continue;
		if (dist[end] > next_cost) {
			if (Dijkstra(n, start, n)) {
				flag = 1;
				break;
			}
		}
	}

	
	if (dist[n] == INF) {
		cout << "-1";
	}
	else {
		if (flag == 1) {
			cout << "-1";
		}
		else {
			int temp = n;
			path.push_back(n);
			while (1) {
				temp = prev_node[temp];
				path.push_back(temp);
				if (temp == 1) {
					break;
				}
			}

			for (int i = path.size()-1; i >= 0; i--) {
				cout << path[i] << ' ';
			}
		}
	}



	return 0;

}