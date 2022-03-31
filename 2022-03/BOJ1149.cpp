#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define R 0
#define G 1
#define B 2

int n;
int cost[1000][3];
int homeCost[1000][3];

int dp(int n,int color) {
	if (homeCost[n][color] != 0) {
		return homeCost[n][color];
	}

	if (n == 0) {
		return cost[0][color];
	}

	homeCost[n][color] = min(dp(n - 1,(color + 1) % 3), dp(n - 1, (color + 2) % 3)) + cost[n][color];

	return homeCost[n][color];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int red, green, blue;
		cin >> red >> green >> blue;
		cost[i][0] = red;
		cost[i][1] = green;
		cost[i][2] = blue;
	}

	int lastHomeR = dp(n - 1, R);
	int lastHomeG = dp(n - 1, G);
	int lastHomeB = dp(n - 1, B);

	if (lastHomeR <= lastHomeG && lastHomeR <= lastHomeB)
		cout << lastHomeR;
	else if (lastHomeG <= lastHomeB)
		cout << lastHomeG;
	else
		cout << lastHomeB;

	return 0;
}