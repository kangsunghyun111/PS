#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

#define INF 1000000000

int n;
int map[100000][3];
int window[2][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	}

	for (int i = 0; i < 3; i++) {
		window[0][i] = map[0][i];
	}

	int left, right;
	for (int i = 1; i < n; i++) {
		left = max(window[0][0], window[0][1]);
		right = max(window[0][1], window[0][2]);

		window[1][0] = left + map[i][0];
		window[1][1] = max(left, right) + map[i][1];
		window[1][2] = right + map[i][2];

		for (int j = 0; j < 3; j++) {
			window[0][j] = window[1][j];
		}
	}

	int ans = max(window[0][0], max(window[0][1], window[0][2]));
	cout << ans << ' ';

	for (int i = 0; i < 3; i++) {
		window[0][i] = map[0][i];
	}

	for (int i = 1; i < n; i++) {
		left = min(window[0][0], window[0][1]);
		right = min(window[0][1], window[0][2]);

		window[1][0] = left + map[i][0];
		window[1][1] = min(left, right) + map[i][1];
		window[1][2] = right + map[i][2];

		for (int j = 0; j < 3; j++) {
			window[0][j] = window[1][j];
		}
	}

	ans = min(window[0][0], min(window[0][1], window[0][2]));
	cout << ans << ' ';

	return 0;
}