#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define PAD 50
int dp[101][101][101];

int w(int a, int b, int c) {
	if (dp[PAD+a][PAD + b][PAD + c] != 0)
		return dp[PAD + a][PAD + b][PAD + c];

	if (a <= 0 || b <= 0 || c <= 0) {
		dp[PAD + a][PAD + b][PAD + c] = 1;
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		int t;
		t = w(20, 20, 20);
		dp[PAD + a][PAD + b][PAD + c] = t;
		return t;
	}
	if (a < b && b < c) {
		int i, j, k;
		i = w(a, b, c - 1);
		dp[PAD + a][PAD + b][PAD + c - 1] = i;

		j = w(a, b - 1, c - 1);
		dp[PAD + a][PAD + b - 1][PAD + c - 1] = j;

		k = w(a, b - 1, c);
		dp[PAD + a][PAD + b - 1][PAD + c] = k;
		return (i + j - k);
	}
	
	int x, y, z, u;
	x = w(a - 1, b, c);
	dp[PAD + a - 1][PAD + b][PAD + c] = x;

	y = w(a - 1, b - 1, c);
	dp[PAD + a - 1][PAD + b - 1][PAD + c] = y;

	z = w(a - 1, b, c - 1);
	dp[PAD + a - 1][PAD + b][PAD + c - 1] = z;

	u = w(a - 1, b - 1, c - 1); 
	dp[PAD + a - 1][PAD + b - 1][PAD + c - 1] = u;

	return x + y + z - u;
		
}

int main() {
	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		int result = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
	}

	return 0;
}