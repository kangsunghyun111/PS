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
	int count;
};

struct compare {
	bool operator()(Node a, Node b) {
		return a.count > b.count;
	}
};

int n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int map[50][50];
int visit[100][50][50];
queue<Node> q;
priority_queue<Node, vector<Node>, compare> pq;


void BFS() {
	while (!q.empty()) {
		Node temp = q.front();
		int x = temp.x;
		int y = temp.y;
		int count = temp.count;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			pq.push(temp);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				int nc;
				if (map[nx][ny] == 1)
					nc = count;
				else if (map[nx][ny] == 0)
					nc = count + 1;

				if (nc == 99)
					continue;

				if (visit[nc][nx][ny] == 0) {
					visit[nc][nx][ny] = 1;
					q.push({ nx,ny,nc });
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - 48;
		}
	}

	Node start = { 0,0,0 };
	visit[0][0][0] = 1;
	q.push(start);
	BFS();

	cout << pq.top().count;

	return 0;
}