#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

struct Node {
	int x;
	int y;
	Node(){}
	Node(int X, int Y) : x(X),y(Y) {}
};

struct Fish {
	int x;
	int y;
	int dist;
	Fish(){}
	Fish(int X, int Y, int D) :x(X), y(Y), dist(D) {}
};

struct compare {
	bool operator()(Fish a, Fish b) {
		if (a.dist != b.dist) {
			return a.dist > b.dist;
		}
		else if(a.dist == b.dist) {
			if (a.x == b.x) {
				return a.y > b.y;
			}
			else {
				return a.x > b.x;
			}
		}
	}
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int N;
int map[20][20];
int visited[20][20];
int dist[20][20];
int ans = 0;
int babySharkSize = 2;
int eatCount = 0;
Node babyShark;
queue<Node> q;
priority_queue<Fish,vector<Fish>,compare> eatableFish;

void sizeCheck() {
	if (eatCount == babySharkSize) {
		eatCount = 0;
		babySharkSize++;
	}
}

Node BFS(Node start) {
	q.push(start);
	visited[start.x][start.y] = 1;
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Node next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];					

			if (next.x >= 0 && next.x < N && next.y >= 0 && next.y < N) {
				if (visited[next.x][next.y] == 0 && map[next.x][next.y] <= babySharkSize) {
					visited[next.x][next.y] = 1;
					dist[next.x][next.y] = dist[cur.x][cur.y] + 1;
					q.push(next);

					if (map[next.x][next.y] != 0 && map[next.x][next.y] != 9 && map[next.x][next.y] < babySharkSize) {
						Fish fish(next.x, next.y, dist[next.x][next.y]);
						eatableFish.push(fish);
					}
				}
			}
		}
	}


	if (eatableFish.size() == 0) {
		return Node(-1, -1);
	}
	else {
		return Node(eatableFish.top().x,eatableFish.top().y);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				babyShark.x = i;
				babyShark.y = j;
			}
		}
	}


	while (1) {
		Node dest = BFS(babyShark);

		// 먹을 수 있는 물고기가 없을 때
		if (dest.x == -1 && dest.y == -1) {
			cout << ans;
			break;
		}
		// 먹을 수 있는 물고기가 있을 때
		else {
			// 아기 상어 이동
			map[babyShark.x][babyShark.y] = 0;
			babyShark.x = dest.x;
			babyShark.y = dest.y;
			map[dest.x][dest.y] = 9;
			ans += dist[dest.x][dest.y];

			// 아기 상어 물고기 먹고 크기 확인
			eatCount++;
			sizeCheck();

			// 변수 초기화
			while (!eatableFish.empty())
				eatableFish.pop();

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					visited[i][j] = 0;
					dist[i][j] = 0;
				}
			}
		}

	}

	return 0;
}