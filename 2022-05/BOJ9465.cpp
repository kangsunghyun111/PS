#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int sticker[2][100000];
int dp[2][100000];
int tc;
int n;

int DP(int i, int j) {
	if (j >= n)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];

	if (i == 0) {
		dp[i][j] = sticker[i][j] + max(max(DP(1, j + 1), DP(0, j + 2)), DP(1, j + 2));
	}
	else {
		dp[i][j] = sticker[i][j] + max(max(DP(0, j + 1), DP(1, j + 2)), DP(0, j + 2));
	}

	return dp[i][j];
}

int main() {
	
	cin >> tc;
	while (tc--) {
		
		cin >> n;
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &sticker[i][j]);
				dp[i][j] = -1;
			}
		}

		int select_zero = DP(0, 0);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1;
			}
		}

		int select_one = DP(1, 0);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1;
			}
		}

		if (select_zero > select_one)
			cout << select_zero << '\n';
		else
			cout << select_one << '\n';


	}
}