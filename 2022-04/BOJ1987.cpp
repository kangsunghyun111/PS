#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
char board[20][20];
int usedAlphabet[26];
int r, c;
int ans;

void DFS(int x, int y, int cnt) {
	if (ans < cnt)
		ans = cnt;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < r
			&& next_y >= 0 && next_y < c) {
			int temp = int(board[next_x][next_y]) - 65;
			if (usedAlphabet[temp] == 1) {

			}
			else {
				usedAlphabet[temp] = 1;
				DFS(next_x, next_y, cnt + 1);
				usedAlphabet[temp] = 0;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			board[i][j] = str[j];
	}


	usedAlphabet[int(board[0][0]) - 65] = 1;
	DFS(0, 0 , 1);

	cout << ans;

	return 0;
}