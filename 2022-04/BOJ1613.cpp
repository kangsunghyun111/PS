#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 100000

int adj[401][401];
int dist[401][401];

int main() {
	int n, k;
	cin >> n >> k;

	int a, b;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
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
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int s;
	cin >> s;
	while (s--) {
		scanf("%d %d", &a, &b);
		if (dist[a][b] == INF) {
			if (dist[b][a] == INF)
				printf("0\n");
			else
				printf("1\n");
		}
		else
			printf("-1\n");
	}

	return 0;
}