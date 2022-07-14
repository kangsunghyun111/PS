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

struct Part {
	int need;
	int num;
};

int n, m;
int need_num[101];
int in_degree[101];
vector<Part> adj[101];
int basic[101];
queue<int> q;

void Get_num(int x) {
	if (basic[x] == 0) {

	}
}

void TopologicalSort() {
	int start = n;
	need_num[n] = 1;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].need;
			int num = adj[cur][i].num;

			need_num[next] += need_num[cur] * num;

			in_degree[next] --;
			if (in_degree[next] == 0)
				q.push(next);

		}
	}

	for (int i = 1; i <= n; i++) {
		if (basic[i] == 0)
			cout << i << ' ' << need_num[i] << "\n";
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int target, need, num;
		scanf("%d %d %d", &target, &need, &num);
		adj[target].push_back({ need,num });
		in_degree[need] ++;
		basic[target] = -1;
	}


	TopologicalSort();

	return 0;
}