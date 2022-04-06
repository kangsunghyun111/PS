#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int stair[300];
int score[300];

int dp(int n) {
	if (n < 0)
		return 0;
	if (score[n] != 0)
		return score[n];
	if (n == 0)
		return score[n] = stair[n];
	if (n == 1)
		return score[n] = stair[n] + stair[n - 1];


	score[n] = max(dp(n - 2) + stair[n], dp(n - 3) + stair[n - 1] + stair[n]);

	return score[n];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stair[i];
	}

	dp(N - 1);

	int max = 0;
	for (int i = 0; i < N; i++)
		if (max < score[i])
			max = score[i];

	cout << max;

	return 0;
}