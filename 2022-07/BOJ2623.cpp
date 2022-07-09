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
vector<int> graph[1001];
vector<int> in_degree;
vector<int> ans;
queue<int> q;

void TopologicalSort() {
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
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
	cin.ignore();

	in_degree.assign(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int num; 
		scanf("%d", &num);
		vector<int> temp;
		for (int j = 0; j < num; j++) {
			int t;
			scanf("%d", &t);
			temp.push_back(t);
		}

		int start, end;
		for (int j = 1; j < temp.size(); j++) {
			start = temp[j - 1];
			end = temp[j];
			graph[start].push_back(end);
			in_degree[end]++;
		}
	}

	TopologicalSort();

	if (ans.size() != n)
		cout << 0;
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
	}


	return 0;
}