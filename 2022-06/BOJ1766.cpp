#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int n, m;
vector<int> adjList[32001];
int in_degree[32001];
priority_queue<int,vector<int>,compare> pq;
vector<int> ans;

void TopologicalSort() {
	while (!pq.empty()) {
		int cur = pq.top();
		ans.push_back(cur);
		pq.pop();

		for (int i = 0; i < adjList[cur].size(); i++) {
			int next = adjList[cur][i];
			in_degree[next]--;
			if (in_degree[next] == 0) {
				pq.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		adjList[start].push_back(end);
		in_degree[end]++;
	}

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			pq.push(i);
		}
	}

	TopologicalSort();

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}