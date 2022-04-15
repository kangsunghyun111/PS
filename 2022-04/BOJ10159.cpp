#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define INF 10000000

int adj[101][101];
int dist[101][101];

int main() {
	int n, m;
	cin >> n >> m;

	int start, end;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &start, &end);
		adj[start][end] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else if (adj[i][j] != 0)
				dist[i][j] = adj[i][j];
			else
				dist[i][j] = INF;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}

	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;

		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				v.push_back(j);
		}

		while (!v.empty()) {
			int temp = v.back();
			v.pop_back();
			if (dist[temp][i]==INF) { // If temp node and i node can not compare
				cnt++;
			}
		}

		cout << cnt << '\n';
	}


	return 0;
}