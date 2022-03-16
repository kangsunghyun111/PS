#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

bool visited[26][26];
int map[27][27];
vector<pair<int, int>> graph[26][26];
vector<int> saveNum;
queue<pair<int, int>> q;

void BFS(int x, int y);

int main() {
	int n;
	int BFSCounter = 0;
	string temp;
	
	cin >> n;
	
	for (int i = 1; i < n+1; i++) {			
		cin >> temp;
		for (int j = 1; j < n+1; j++) {
			map[i][j] = temp[j-1] - 48;
		}
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n+1; j++) {
			if (map[i][j] == 1) {
				if (map[i-1][j]) {
					graph[i][j].push_back(pair<int, int>(i - 1, j));
				}
				if (map[i][j-1]) {
					graph[i][j].push_back(pair<int, int>(i, j - 1));
				}
				if (map[i][j+1]) {
					graph[i][j].push_back(pair<int, int>(i, j + 1));
				}
				if (map[i+1][j]) {
					graph[i][j].push_back(pair<int, int>(i + 1, j));
				}
			}
		}
	}


	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			if (map[i][j] == 1) {
				if (visited[i][j] == 0) {
					BFS(i, j);
					BFSCounter++;
				}
			}
		}
	}

	cout << BFSCounter << '\n';
	sort(saveNum.begin(), saveNum.end());
	for (int i = 0; i < saveNum.size(); i++)
		cout << saveNum[i] << '\n';

	return 0;
}

void BFS(int x, int y) {
	q.push(pair<int, int>(x, y));
	int count = 1;
	visited[x][y] = 1;

	while (!q.empty()) {
		pair<int, int> r = q.front();
		q.pop();

		for (int i = 0; i < graph[r.first][r.second].size(); i++) {
			pair<int, int> k = graph[r.first][r.second][i];

			if (visited[k.first][k.second] == 0) {
				count++;
				visited[k.first][k.second] = 1;
				q.push(graph[r.first][r.second][i]);
			}
		}

	}

	saveNum.push_back(count);
}