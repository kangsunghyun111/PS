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

int t, n, k, w;
vector<int> constructionTime;
vector<int> minConstTime;
vector<int> building[1001];
vector<int> in_degree;
queue<int> q;

void TopologicalSort(int w) {
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			minConstTime[i] = constructionTime[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < building[cur].size(); i++) {
			int next = building[cur][i];
			minConstTime[next] = max(minConstTime[next], minConstTime[cur] + constructionTime[next]);
			
			in_degree[next]--;			
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}
	}

	cout << minConstTime[w] << "\n";
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		constructionTime.assign(n + 1, 0);
		in_degree.assign(n + 1, 0);
		minConstTime.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			int t;
			scanf("%d", &t);
			constructionTime[i] = t;
		}
		for (int i = 1; i <= k; i++) {
			int start, end;
			scanf("%d %d", &start, &end);
			building[start].push_back(end);
			in_degree[end]++;
		}
		cin >> w;
		TopologicalSort(w);
		for (int i = 1; i <= n; i++) {
			building[i].clear();
		}
	}
}