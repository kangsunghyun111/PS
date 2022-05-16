#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
#define INF 1234567890

int f, s, g, u, d;
int map[1000001];
int visited[1000001];
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		int next = cur + u;
		if (next > 0 && next <= f && visited[next] == 0) {
			visited[next] = 1;
			map[next] = map[cur] + 1;
			q.push(next);
		}

		next = cur - d;
		if (next > 0 && next <= f && visited[next] == 0) {
			visited[next] = 1;
			map[next] = map[cur] + 1;
			q.push(next);
		}
	}
}

int main() {
	cin >> f >> s >> g >> u >> d;

	for (int i = 0; i <= f; i++)
		map[i] = INF;

	map[s] = 0;
	visited[s] = 1;
	q.push(s);
	BFS();

	if (map[g] == INF)
		cout << "use the stairs";
	else
		cout << map[g];

	return 0;
}