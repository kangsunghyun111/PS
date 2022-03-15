#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[1001];
bool visited2[1001];
vector<int> graph[1001];
queue<int> q;

void DFS(int v);
void BFS(int v);

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	for (int i = 0; i < 1001; i++) {
		if (graph[i].size() != 0) {
			sort(graph[i].begin(), graph[i].end());
			graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
			//for (int j = 0; j < graph[i].size(); j++) {
			//	cout << i << ' ' << graph[i][j] << " \n";
			//}
		}
	}

	DFS(start);
	cout << '\n';

	BFS(start);
	cout << '\n';

	return 0;
}

void DFS(int v) {
	if (visited[v] == 0) {
		visited[v] = 1;
		cout << v << ' ';
		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i];
			DFS(next);
		}
	}
}

void BFS(int v) {
	q.push(v);
	visited2[v] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (visited2[y] == 0) {
				q.push(y);
				visited2[y] = 1;
			}
		}
	}

}