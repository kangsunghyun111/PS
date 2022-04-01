#include <iostream>
#include <algorithm>
using namespace std;

int triangle[500][500];
int cost[500][500];

int dp(int n, int k) {
	if (cost[n][k] != -1)
		return cost[n][k];

	if (n == 0) {
		cost[0][0] = triangle[0][0];
		return cost[0][0];
	}

	if (n == k) {
		cost[n][k] = triangle[n][k] + dp(n - 1, k - 1);
		return cost[n][k];
	}

	if (k == 0) {
		cost[n][k] = triangle[n][k] + dp(n - 1, k);
		return cost[n][k];
	}

	cost[n][k] = max(dp(n - 1, k), dp(n - 1, k - 1)) + triangle[n][k];
	return cost[n][k];
}

int main() {
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++)
			cost[i][j] = -1;
	}
	int n;
	cin >> n;

	int temp;
	int pad = 1;
	int iter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < pad; j++) {
			cin >> temp;
			triangle[i][j] = temp;
		}
		pad++;
	}

	for (int i = 0; i < n; i++) {
		dp(n - 1, i);
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < cost[n - 1][i])
			max = cost[n - 1][i];
	}

	cout << max;

	return 0;
}