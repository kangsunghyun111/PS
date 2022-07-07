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

int n, m;
vector<int> student[32001];
int in_degree[32001];
queue<int> q;
vector<int> ans;

void TopologicalSort() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < student[cur].size(); i++) {
			int next = student[cur][i];
			in_degree[next]--;
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}
		ans.push_back(cur);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		student[start].push_back(end);
		in_degree[end]++;
	}

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	TopologicalSort();

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}