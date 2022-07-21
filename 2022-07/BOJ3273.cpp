#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdio.h> 
#pragma warning(disable:4996)

using namespace std;

#define INF 1000000000
#define LLINF 9223372036854775800

int seq[100001];

int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	cin >> x;

	int left = 0;
	int right = n - 1;
	int ans = 0;

	sort(seq, seq + n);

	while (left != right) {
		int sum = seq[left] + seq[right];
		if (sum == x) {
			ans++;
			right--;
			continue;
		}
		else if (sum > x) {
			right--;
		}
		else {
			left++;
		}
	}

	return 0;
}