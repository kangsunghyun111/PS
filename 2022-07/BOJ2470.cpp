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

#define INF 2100000000
#define LLINF 9223372036854775800

int seq[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	sort(seq, seq + n);

	int left = 0;
	int right = n - 1;
	int ans_L = 0;
	int ans_R = 0;
	int min_sum = INF;

	while (left != right) {
		int sum = seq[left] + seq[right];
		if (min_sum>abs(sum)) {
			min_sum = abs(sum);
			ans_L = left;
			ans_R = right;
		}

		if (sum == 0) {
			break;
		}
		else if (sum > 0) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << seq[ans_L] << ' ' << seq[ans_R];

	return 0;
}