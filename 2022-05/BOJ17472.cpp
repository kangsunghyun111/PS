#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
#define INF 1234567890
struct Edge {
	int start;
	int end;
	int cost;
	Edge(){}
	Edge(int X, int Y, int Z) : start(X), end(Y), cost(Z) {}
};
struct compare {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

int n, m;
int island_id = 1;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map[10][10];
int new_map[10][10];
int visited[10][10];
vector<pair<int,int>> island;
vector<int> connect_check[7];
int visited_check[7];

priority_queue<Edge, vector<Edge>, compare> pq;
int parent[7];
int MST_cost;

int find_parent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y) {
	int x_p = find_parent(x);
	int y_p = find_parent(y);
	if (parent[x_p] < parent[y_p])
		parent[y_p] = parent[x_p];
	else
		parent[x_p] = parent[y_p];
}

bool isCycle(int x, int y) {
	int x_p = find_parent(x);
	int y_p = find_parent(y);
	if (x_p == y_p)
		return 1;
	else
		return 0;
}

void Kruskal() {
	for (int i = 0; i < 8; i++) {
		parent[i] = i;
	}
	while (!pq.empty()) {
		Edge temp = pq.top();
		int start = temp.start;
		int end = temp.end;
		int cost = temp.cost;
		pq.pop();
		if (isCycle(start, end) == 0) {
			MST_cost += cost;
			connect_check[start].push_back(end);
			connect_check[end].push_back(start);
			union_parent(start, end);
		}
	}
}

void find_island(int start_id, int dir, int x, int y) {
	int next_x = x;
	int next_y = y;
	int dist = 1;
	while (1) {			
		next_x = next_x + dx[dir];
		next_y = next_y + dy[dir];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
			if (new_map[next_x][next_y] == 0) {
				// keep find
				dist++;
			}
			else {
				int start = start_id;
				int end = new_map[next_x][next_y];
				int cost = dist;
				if (cost >= 2) {
					pq.push(Edge(start, end, cost));
				}
				break;
			}
		}
		else {
			break;
		}	
	}
}

void check_edge(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		int direction = i;
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
			if (new_map[next_x][next_y] == 0) {
				find_island(new_map[x][y], direction, next_x, next_y);
			}
		}
	}
}

void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
			if (visited[next_x][next_y] == 0 && map[next_x][next_y] == 1) {
				visited[next_x][next_y] = 1;
				new_map[next_x][next_y] = island_id;
				DFS(next_x, next_y);
			}
		}
	}
}

void DFS(int x) {
	visited_check[x] = 1;
	for (int i = 0; i < connect_check[x].size(); i++) {
		int next_x = connect_check[x][i];
		if (visited_check[next_x] == 0) {
			DFS(next_x);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0)
				island.push_back({ i,j });
		}
	}

	for (int i = 0; i < island.size(); i++) {
		int x = island[i].first;
		int y = island[i].second;
		if (visited[x][y] == 0) {
			new_map[x][y] = island_id;
			DFS(x, y);
			island_id++;
		}
	}

	for (int i = 0; i < island.size(); i++) {
		int x = island[i].first;
		int y = island[i].second;
		check_edge(x, y);
	}

	Kruskal();

	DFS(1);

	for (int i = 1; i < island_id; i++) {
		if (visited_check[i] == 0) {
			cout << -1;
			return 0;
		}
	}

	cout << MST_cost;

	return 0;
}