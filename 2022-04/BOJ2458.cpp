#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define INF 10000000

int adj[501][501];
int dist[501][501];


int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int small, tall;
		//cin >> small >> tall;
		scanf("%d %d", &small, &tall);
		adj[small][tall] = 1;
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

	for (int k = 1; k <= n; k++) { // Via node
		for (int i = 1; i <= n; i++) { // Start node
			for (int j = 1; j <= n; j++) { // End node
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int cnt = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				v.push_back(j);
		}

		int flag = 1;
		while (!v.empty()) {
			int check = v.back();
			v.pop_back();
			if (dist[check][i] == INF)
				flag = 0;
		}

		if (flag)
			cnt++;
	}

	cout << cnt;

	return 0;
}