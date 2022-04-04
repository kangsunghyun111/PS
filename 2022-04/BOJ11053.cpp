#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int sequence[1000];
int len[1000];

void dp(int N) {
	for (int i = 0; i < N; i++) {
		len[i] = 1;
		for (int j = 0; j < i; j++) {
			if (sequence[i] > sequence[j]) {
				len[i] = max(len[i], len[j] + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	dp(n);

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < len[i])
			max = len[i];
	}

	cout << max;

	return 0;
}