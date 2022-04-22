#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define INF 1000

int dist[51][51];
int arr[51][51];

int main() {
	int n;
	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else if (arr[i][j] != 0) {
				dist[i][j] = arr[i][j];
			}
			else {
				dist[i][j] = INF;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int score = INF;
	int cnt = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {	
		int max = 0;

		for (int j = 1; j <= n; j++) {
			if (max < dist[i][j] && dist[i][j] != 0) {
				max = dist[i][j];
			}
		}

		if (score > max) {
			score = max;
			cnt = 0;
			v.clear();
		}

		if (score == max) {
			cnt++;
			v.push_back(i);
		}
	}

	cout << score << ' ' << cnt << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}