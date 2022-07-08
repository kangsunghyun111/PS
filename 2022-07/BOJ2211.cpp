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

struct Node {
	int end;
	int cost;
};

struct compare {
	bool operator()(Node a, Node b) {
		return b.cost > a.cost;
	}
};


int n, m;
vector<Node> computer[1001];

void Dijkstra() {
	priority_queue<Node, vector<Node>, compare> pq;
	vector<int> dist;
	vector<pair<int, int>> path;
	vector<int> ans;

	ans.assign(n + 1, 0);
	dist.assign(n + 1, INF);
	dist[1] = 0;
	pq.push({ 1,dist[1] });
	
	while (!pq.empty()) {
		Node temp = pq.top();
		int cur = temp.end;
		int cost = temp.cost;
		pq.pop();
		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < computer[cur].size(); i++) {
			temp = computer[cur][i];
			int next = temp.end;
			int next_cost = cost + temp.cost;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next,next_cost });
				path.push_back({cur,next});
			}
		}
	}
	
	for (int i = 0; i < path.size(); i++) {
		ans[path[i].second] = path[i].first;
	}

	cout << n - 1 << "\n";
	for (int i = 2; i < ans.size(); i++) {
		cout << i << ' ' << ans[i] << "\n";
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		computer[start].push_back({ end,cost });
		computer[end].push_back({ start,cost });
	}

	Dijkstra();

	return 0;
}