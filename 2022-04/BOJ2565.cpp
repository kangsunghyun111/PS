#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> line;
int B[101];
int len[101];
int N;

int dp(int n) {
	int LIS = 0;
	for (int i = 0; i < n; i++) {
		len[i] = 1;
		for (int j = 0; j < i; j++) {
			if (B[i] > B[j]) {
				len[i] = max(len[i], len[j] + 1);
				if (LIS < len[i])
					LIS = len[i];
			}
		}
	}
	return LIS;
}

int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		line.push_back({ a,b });
	}

	sort(line.begin(), line.end());

	for (int i = 0; i < N; i++) {
		B[i] = line[i].second;
	}

	int LIS = dp(N);

	cout << N - LIS;


	return 0;
}