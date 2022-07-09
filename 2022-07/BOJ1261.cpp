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

struct Node {
	int x;
	int y;
	int brokeNum;
};

struct compare {
	bool operator()(Node a, Node b) {
		return a.brokeNum > b.brokeNum;
	}
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int m, n;
int map[100][100];
int broke[100][100];

void Dijkstra() {
	priority_queue<Node, vector<Node>, compare> pq;
	broke[0][0] = 0;
	pq.push({ 0,0,broke[0][0] });

	while (!pq.empty()) {
		Node temp = pq.top();
		int x = temp.x;
		int y = temp.y;
		int brokeNum = temp.brokeNum;
		pq.pop();

		if (broke[x][y] < brokeNum)
			continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nb;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (map[nx][ny] == 1)
				nb = brokeNum + 1;
			else
				nb = brokeNum;

			if (broke[nx][ny] > nb) {
				broke[nx][ny] = nb;
				pq.push({ nx,ny,nb });
			}
		}
	}
	cout << broke[n - 1][m - 1];
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			broke[i][j] = INF;
		}
	}


	Dijkstra();

	return 0;
}