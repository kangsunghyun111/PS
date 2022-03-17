#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[50][50];
int map[50][50];
int t, m, n, k;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void DFS(int x,int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx >= 0 && yy >= 0 && xx < m && yy < n&&visited[xx][yy]==0&&map[xx][yy]==1) {
			DFS(xx, yy);
		}
	}
}

int main() {
	int tempX, tempY;

	cin >> t;

	while (t--) {

		// Init count and map, visited list
		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> tempX >> tempY;
			map[tempX][tempY] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j]) {
					if (visited[i][j] == 0) {
						DFS(i, j);
						count++;
					}
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}