#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MOD 15746
int N;
int arr[1000000];

int DP(int n) {
	if (arr[n] != 0)
		return arr[n];
	if (n == 0)
		return arr[n] = 1;
	if (n == 1)
		return arr[n] = 2;
	
	return arr[n] = DP(n - 1) % MOD + DP(n - 2) % MOD;
}

int main() {
	cin >> N;
	DP(N - 1);

	cout << arr[N - 1] % MOD;

	return 0;
}