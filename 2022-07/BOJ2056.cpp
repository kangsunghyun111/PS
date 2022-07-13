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

int n;
int t[10001];
vector<int> adj[10001];
int min_time[10001];
int in_degree[10001];
queue<int> q;

void TopologicalSort() {
	vector<int> seq;
	int ans = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			in_degree[next]--;
			min_time[next] = max(min_time[next], min_time[cur] + t[next]);
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}
		seq.push_back(cur);
	}

	for (int i = 1; i <= n; i++) {
		if (ans < min_time[i])
			ans = min_time[i];
	}

	cout << ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int cost, num;
		scanf("%d %d", &cost, &num);
		t[i] = cost;
		if (num == 0) {
			min_time[i] = cost;
			q.push(i);
		}
		for (int j = 0; j < num; j++) {
			int need;
			scanf("%d", &need);
			adj[need].push_back(i);
			in_degree[i]++;
		}
	}

	TopologicalSort();

	return 0;
}