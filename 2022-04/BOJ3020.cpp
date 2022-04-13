#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, H;
vector<int> bot;
vector<int> top;

int main() {
	cin >> N >> H;
	for (int i = 0; i < N/2; i++) {
		int a, b;
		scanf_s("%d%d", &a, &b);
		bot.push_back(a);
		top.push_back(b);
	}

	sort(bot.begin(), bot.end());
	sort(top.begin(), top.end());

	int min = 1000000;
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		int botIndex, topIndex;
		botIndex = lower_bound(bot.begin(), bot.end(), i) - bot.begin();
		topIndex = lower_bound(top.begin(), top.end(), H - i + 1) - top.begin();
		int sum = N - (botIndex + topIndex);

		if (min > sum) {
			min = sum;
			cnt = 1;
		}
		else if (min == sum)
			cnt++;
	}

	cout << min << ' ' << cnt;

	return 0;
}