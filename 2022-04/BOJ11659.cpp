#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int N, M;
int arr[100000];

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i < N; i++) {
		arr[i] = arr[i] + arr[i - 1];
	}

	while (M--) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		a--;
		b--;
		printf("%d\n", arr[b] - arr[a - 1]);
	}

	return 0;
}