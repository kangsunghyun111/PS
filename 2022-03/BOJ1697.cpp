#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;

int map[100001];
bool visited[100001];

queue<int> q;

int dx[2] = { -1,1 };

void BFS() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		visited[x] = 1;

		for (int i = 0; i < 3; i++) {
			int next_x;
			if (i == 2) {
				next_x = 2 * x;
				if (next_x >= 0 && next_x <= 100000
					&& visited[next_x] == 0) {

					visited[next_x] = 1;
					map[next_x] = map[x] + 1;
					q.push(next_x);
				}
				continue;
			}
			next_x = x + dx[i];
			if (next_x >= 0 && next_x <= 100000
				&& visited[next_x] == 0) {

				visited[next_x] = 1;
				map[next_x] = map[x] + 1;
				q.push(next_x);
			}
		}

	}
}

int main() {
	cin >> n >> k;
	q.push(n);
	BFS();

	cout << map[k];
	return 0;
}