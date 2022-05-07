#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

#define INF	123456789
struct node {
	int dest;
	int fee;
	int time;
};
struct compare {
	bool operator()(node a, node b) {
		return a.time > b.time;
	}
};

vector<node> vertex[101];
vector<int> dp[101];

void Dijkstra(int n,int m) {
	priority_queue<node, vector<node>, compare> pq;
	for (int i = 0; i <= n; i++) {
		dp[i].assign(m + 1, INF);
	}
	node temp = { 1,0,0 };
	pq.push(temp);


	while (!pq.empty()) {
		int cur = pq.top().dest;
		int fee = pq.top().fee;
		int time = pq.top().time;
		pq.pop();

		if (dp[cur][fee] < time)
			continue;

		for (int i = 0; i < vertex[cur].size(); i++) {
			int next = vertex[cur][i].dest;
			int next_fee = fee + vertex[cur][i].fee;
			int next_time = time + vertex[cur][i].time;

			if (next_fee > m)
				continue;

			if (dp[next][next_fee] > next_time) {

				for (int j = next_fee + 1; j <= m; j++) {
					if (dp[next][j] <= next_time)
						break;
					dp[next][j] = next_time;
				}

				dp[next][next_fee] = next_time;
				pq.push({ next,next_fee,next_time });
			}
		}
	}

	int min = INF;
	for (int i = 1; i <= m; i++) {
		if (min > dp[n][i])
			min = dp[n][i];
	}

	if (min == INF)
		cout << "Poor KCM" << '\n';
	else
		cout << min << '\n';
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int start, end, fee, time;
			scanf("%d %d %d %d", &start, &end, &fee, &time);
			node temp = { end,fee,time };
			vertex[start].push_back(temp);
		}

		Dijkstra(n, m);

		for (int i = 1; i <= n; i++)
			vertex[i].clear();

	}
}