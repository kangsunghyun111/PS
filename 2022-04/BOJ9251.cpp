#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string a;
string b;
int dp[1001][1001];

void fun_dp() {
	int LCS = 0;
	for (int i = 1; i < b.length(); i++) {
		for (int j = 1; j < a.length(); j++) {
			if (a[j] == b[i]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (LCS < dp[i][j])
					LCS = dp[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << LCS;
}

int main() {
	cin >> a >> b;
	a = "0" + a;
	b = "0" + b;

	fun_dp();

	return 0;
}