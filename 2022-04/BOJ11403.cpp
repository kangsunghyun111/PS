#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000
int adj[100][100];
int dist[100][100];


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			adj[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				dist[i][j] = INF;
			else if (adj[i][j] != 0)
				dist[i][j] = adj[i][j];
			else
				dist[i][j] = INF;
		}
	}

	for (int k = 0; k < N; k++) { // Via node
		for (int i = 0; i < N; i++) { // Start node
			for (int j = 0; j < N; j++) { // End node
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INF)
				cout << "0 ";
			else
				cout << "1 ";
		}
		cout << '\n';
	}
	

	return 0;
}