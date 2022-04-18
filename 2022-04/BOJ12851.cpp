#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int cnt,minTime;
int dx[2] = { -1,1 };
int visited[100001];
queue<pair<int, int>> q; // Location, time

void BFS() {
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();
		visited[cur] = 1;

		if (cnt != 0 && minTime == time && cur == k)
			cnt++;

		if (cnt == 0 && cur == k) {
			minTime = time;
			cnt++;
		}

		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 2)
				next = cur * 2;
			else
				next = cur + dx[i];

			if (next >= 0 && next <= 100000
				&& visited[next] == 0) {
				q.push({ next,time + 1 });
			}
		}
	}
}

int main() {
	cin >> n >> k;
	q.push({ n,0 }); // Start location, time
	BFS();
	cout << minTime << '\n' << cnt;

	return 0;
}