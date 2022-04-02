#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MOD 1000000000

int N;
int arr[100][10];

int dp(int n, int k) {
	if (k < 0 || k>9)
		return 0;

	if (arr[n][k] != 0)
		return arr[n][k];

	if (n == 0) {
		if (k == 0)
			return 0;
		else {
			arr[0][k] = 1;
			return arr[0][k];
		}
	}

	arr[n][k] = dp(n - 1, k - 1) % MOD + dp(n - 1, k + 1) % MOD;
	return arr[n][k];
}

int main() {
	cin >> N;
	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp(N - 1, i);
	}

	cout << result % MOD;

	return 0;
}