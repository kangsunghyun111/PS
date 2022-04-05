#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int sequence[100000];
int sum[100000];

void dp(int n) {
	sum[0] = sequence[0];

	int result = sum[0];
	for (int i = 1; i < n; i++) {
		sum[i] = max(sum[i - 1] + sequence[i], sequence[i]);
		result = max(sum[i], result);
	}
	cout << result;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	dp(n);

	return 0;
}