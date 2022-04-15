#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define INF 10000000

int adj[401][401];
int dist[401][401];

int main() {
	int v, e;
	cin >> v >> e;

	int start, end, cost;
	for (int i = 1; i <= e; i++) {
		scanf("%d %d %d", &start, &end, &cost);
		adj[start][end] = cost;
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j)
				dist[i][j] = INF;
			else if (adj[i][j] != 0)
				dist[i][j] = adj[i][j];
			else
				dist[i][j] = INF;
		}
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}

	int flag = 0;
	int min = INF;
	for (int i = 1; i <= v; i++) {
		if (dist[i][i] == INF)
			continue;
		else {
			flag = 1;
			if (min > dist[i][i])
				min = dist[i][i];
		}
	}

	if (flag == 0)
		cout << "-1";
	else
		cout << min;

	return 0;
}