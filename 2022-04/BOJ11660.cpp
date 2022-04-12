#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int N, M;
int arr[1025][1025];

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	while (M--) {
		int x1, y1, x2, y2;
		int sum = 0;
		scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = 0; i < x2 - x1 + 1; i++) {
			sum += arr[x1 + i][y2] - arr[x1 + i][y1 - 1];
		}
		printf_s("%d\n", sum);
	}

	return 0;
}