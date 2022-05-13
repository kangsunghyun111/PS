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
	Node() {}
	Node(int X,int Y) : end(X), cost(Y) {}
};
struct compare {
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

vector<Node> vertex[100001];
int n;

Node Dijkstra(int n,int x) {
	priority_queue < Node, vector<Node>, compare> pq;
	vector<long long> dist;
	Node temp;
	Node farthest_node(0,0);
	dist.assign(n + 1, INF);
	dist[x] = 0;
	temp.end = x;
	temp.cost = dist[x];
	pq.push(temp);

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

				if (farthest_node.cost < next_cost) {
					farthest_node.cost = next_cost;
					farthest_node.end = next;
				}
			}
		}
	}

	return Node(farthest_node);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int start, end, cost;
		cin >> start;
		while (1) {
			Node temp;
			cin >> end;
			if (end == -1)
				break;
			cin >> cost;

			temp.end = end;
			temp.cost = cost;
			vertex[start].push_back(temp);
		}
	}

	Node temp;
	temp = Dijkstra(n, 1);

	temp = Dijkstra(n, temp.end);

	cout << temp.cost;

	return 0;
}