#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

int n;
vector<int> adjList[501];
int in_degree[501];
int cost[501];
int ans[501];
queue<int> q;

void TopologicalSort() {
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			ans[i] = cost[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adjList[cur].size(); i++) {
			int next = adjList[cur][i];
			in_degree[next]--;

			if (in_degree[next] == 0) {
				q.push(next);
			}

			ans[next] = max(ans[next], ans[cur] + cost[next]);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		while (1) {
			int input;
			scanf("%d", &input);
			if (input == -1)
				break;
			adjList[input].push_back(i);
			in_degree[i]++;
		}
	}



	TopologicalSort();

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}