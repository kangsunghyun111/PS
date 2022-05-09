#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
int cardpack[10001];
int dp[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cardpack[i];
	}

	dp[1] = cardpack[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + cardpack[j]);
		}
	}

	cout << dp[n];

	return 0;
}