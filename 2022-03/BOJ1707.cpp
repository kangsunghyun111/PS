#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
	
int k, v, e;

vector<pair<int, int>> graph[200001];
queue<pair<int, int>> q;
bool visited[200001];

bool BFS() {

	while (!q.empty()) {
		int x = q.front().first;
		int state = q.front().second;
		visited[x] = 1;
		q.pop();

		for (int i = 1; i < graph[x].size(); i++) {

			int next_x = graph[x][i].first;
			int next_state = graph[x][i].second;

			if (visited[next_x] == 1) {
				graph[x][i].second = graph[next_x][0].second;
				next_state = graph[x][i].second;
			}

			// If next state does not determine
			if (next_state == 0) {
				next_state = state * (-1);

				graph[x][i].second = next_state;
				graph[next_x][0].second = next_state;

				visited[next_x] = 1;
				q.push({ next_x,next_state });
			}
			else if (next_state != 0) {
				if (state == next_state) {
					return false;
				}
			}
		}
	}

	for (int i = 0; i < v; i++) {
		if (visited[i + 1] == 0) {
			q.push({ i + 1,1 });
			return BFS();
		}
	}

	return true;
}

int main() {
	cin >> k;
	int sol[5];
	int cnt = 0;
	for(int t=0;t<k;t++){
		cin >> v >> e;

		// State init
		for (int i = 0; i < v; i++) {
			graph[i + 1].push_back({ i + 1,0 });
		}
		
		// Two-way edge
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back({ b,0 });
			graph[b].push_back({ a,0 });
		}

		// Push({1,1})
		graph[1][0].second = 1;
		q.push({ graph[1][0].first, graph[1][0].second });	

		sol[cnt] = BFS();

		for (int i = 0; i < v; i++) {
			graph[i + 1].clear();
			visited[i + 1] = 0;
		}

		while (!q.empty())
			q.pop();

		cnt++;
	}

	for (int i = 0; i < k; i++) {
		if (sol[i])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}