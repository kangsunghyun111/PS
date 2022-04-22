#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int n, m;
vector<pair<pair<int,int>,int>> busRoute;
vector<long long> dist(501,INF);

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		busRoute.push_back({ {start,end},cost });
	}

	dist[1] = 0;
	for (int i = 1; i <= n-1; i++) {
		for (int j = 0; j < busRoute.size(); j++) {
			int start = busRoute[j].first.first;
			int end = busRoute[j].first.second;
			int cost = busRoute[j].second;
			long long next_cost = cost + dist[start];
			if (dist[start] == INF)
				continue;
			if (dist[end] > next_cost) {
				dist[end] = next_cost;
			}
		}
	}

	for (int i = 0; i < busRoute.size(); i++) {
		int start = busRoute[i].first.first;
		int end = busRoute[i].first.second;
		int cost = busRoute[i].second;
		long long next_cost = cost + dist[start];
		if (dist[start] == INF)
			continue;
		if (dist[end] > next_cost) {
			cout << "-1";
			return 0;
		}
	}


	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF)
			cout << "-1" << '\n';
		else
			cout << dist[i] << '\n';
	}

	return 0;
}