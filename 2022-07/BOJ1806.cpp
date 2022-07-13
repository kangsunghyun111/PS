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
#define LLINF 9223372036854775800

int seq[100000];

int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	int left = 0;
	int right = 0;
	int sum = seq[0];
	int ans = INF;
	
	while (right <= n) {

		if (sum < s) {
			right++;
			sum += seq[right];
		}
		else if (sum >= s) {
			int temp = right - left + 1;
			if (ans > temp)
				ans = temp;

			sum -= seq[left];
			left++;
		}
	}
	if (ans == INF)
		cout << 0;
	else
		cout << ans;

	return 0;
}