#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int board[15];
int result = 0;
int n;

bool isValid(int level) {
	for (int i = 1; i < level; i++) {
		if (board[i] == board[level])
			return false;
		if ((board[i] - board[level]) == (i - level))
			return false;
		if ((board[level] - board[i]) == (i - level))
			return false;
	}
	return true;
}

void bt(int level) {
	if (n+1 == level) {
		result++;
		return;
	}

	for (int i = 1; i <= n; i++) {			
		board[level] = i;
		if (isValid(level)) {
			bt(level + 1);
			board[level] = 0;
		}
		board[level] = 0;
	}
}

int main() {
	cin >> n;

	bt(1);
	cout << result;
}