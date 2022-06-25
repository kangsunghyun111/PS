#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

int t, n;
int cnt;
int choice[100001];
int visited[100001];
int done[100001];

void DFS(int k) {
	visited[k] = 1;
	int next = choice[k];
	if (visited[next] == 0) {
		DFS(next);
	}
	else if (done[next] == 0) {
		for (int i = next; i != k; i = choice[i]) {
			cnt++;
		}
		cnt++;
	}
	done[k] = 1;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			scanf("%d", &choice[i]);
		}

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			DFS(i);
		}

		for (int i = 1; i <= n; i++) {
			choice[i] = 0;
			visited[i] = 0;
			done[i] = 0;
		}

		cout << n - cnt << "\n";
	}

	return 0;
}