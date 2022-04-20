#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 100001

int n, k;
queue<int> q;
int cost[100001];
int visited[100001];
int path[100001];

void BFS() {
	while (!q.empty()) {
		int cur = q.front();
		if (cur == k) break;
		q.pop();
		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 0) {
				next = cur - 1;
			}
			if (i == 1) {
				next = cur + 1;
			}
			if (i == 2) {
				next = cur * 2;
			}

			if (next >= 0 && next <= 100000 && visited[next] == 0) {
				visited[next] = 1;
				cost[next] = cost[cur] + 1;
				path[next] = cur;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> k;

	if (n > k) {
		cout << n - k << '\n';
		for (int i = 0; i < n - k; i++) {
			cout << n - i << ' ';
		}
		cout << k;
	}
	else {		
		q.push(n);
		visited[n] = 1;
		BFS();
		cout << cost[k] << '\n';
		vector<int> v;
		int next = k;
		v.push_back(k);
		for (int i = 0; i < cost[k]; i++) {
			next = path[next];
			v.push_back(next);
		}
		for (int i = v.size() - 1; i >= 0; i--)
			cout << v[i] << ' ';
	}

	return 0;
}