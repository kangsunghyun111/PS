#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited2[1001];	// For BFS
vector<int> graph[1001];	// Graph
queue<int> q;	// For BFS

void BFS(int v);

int main() {
	int n, edge, start;
	cin >> n;
	cin >> edge;
	start = 1;
	
	for (int i = 0; i < edge; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		
		// Two-way edge
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	for (int i = 0; i < 1001; i++) {
		if (graph[i].size() != 0) {

			// Sort and remove duplicate numbers
			sort(graph[i].begin(), graph[i].end());
			graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());

			// To check the results of sorting and deleting
			//for (int j = 0; j < graph[i].size(); j++) {
			//	cout << i << ' ' << graph[i][j] << " \n";
			//}
		}
	}

	BFS(start);

	return 0;
}

void BFS(int v) {
	int count = 0;
	q.push(v);
	visited2[v] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (visited2[y] == 0) {
				count++;
				q.push(y);
				visited2[y] = 1;
			}
		}
	}

	cout << count;
}