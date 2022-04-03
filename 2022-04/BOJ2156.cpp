#include <iostream>
#include <algorithm>
using namespace std;

int n;
int wine[10000];
int cost[10000];

int dp(int n) {
	if (n < 0)
		return 0;
	if (cost[n] != -1)
		return cost[n];
	if (n == 0)
		return cost[0] = wine[0];
	if (n == 1)
		return cost[1] = wine[0] + wine[1];

	cost[n] = max(max(dp(n - 3) + wine[n - 1] + wine[n], dp(n - 2) + wine[n]), dp(n - 1));
	return cost[n];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
		cost[i] = -1;
	}
	
	dp(n - 1);

	int max = 0;
	for (int i = 0; i < n; i++)
		if (max < cost[i])
			max = cost[i];

	cout << max;

	return 0;
}