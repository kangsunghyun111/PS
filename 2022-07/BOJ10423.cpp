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

struct Edge {
	int start;
	int end;
	int cost;
};

struct Node {
	int num;
	bool electric;
};

struct compare {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

int n, m, k;
vector<int> plant;
vector<Node> city;
vector<int> graph[1001];
priority_queue<Edge,vector<Edge>,compare> pq;
int parent[1001];
int MST_cost;

bool All_supplied() {
	queue<int> q;
	int visit[1001];
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < plant.size(); i++)
		q.push(plant[i]);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (visit[next] == 0) {
				visit[next] = 1;
				city[next].electric = 1;
				q.push(next);
			}
		}
	}

	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (city[i].electric == 0) {
			flag = 1;
		}
	}

	if (flag)
		return false;
	else
		return true;
}

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

bool isCycle(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x == y)
		return 1;
	else
		return 0;
}

void Kruskal() {
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	while (!pq.empty()) {
		Edge temp = pq.top();
		int start = temp.start;
		int end = temp.end;
		int cost = temp.cost;
		pq.pop();

		if (city[start].electric == 1 && city[end].electric == 1)
			continue;
		
		if (isCycle(start, end) == 0) {
			unionParent(start, end);		
			graph[start].push_back(end);
			graph[end].push_back(start);

			int flag = All_supplied();

			//cout << start << ' ' << end << ' ' << flag << "\n";
			
			MST_cost += cost;

			if (flag) {
				cout << MST_cost;
				return;
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i <= n; i++) {
		city.push_back({ i,0 });
	}

	for (int i = 0; i < k; i++) {
		int p;
		scanf("%d", &p);
		plant.push_back(p);
		city[p].electric = 1;
	}

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		pq.push({ start,end,cost });

	}

	Kruskal();

	return 0;
}