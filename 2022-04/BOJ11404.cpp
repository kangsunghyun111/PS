#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 100000000

int adj[101][101];
int dist[101][101];


int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		if (adj[start][end] == 0)
			adj[start][end] = cost;
		else {
			if (adj[start][end] > cost)
				adj[start][end] = cost;
		}
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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF)
				cout << dist[i][j] << ' ';
			else
				cout << "0 ";
		}
		cout << '\n';
	}

	return 0;
}