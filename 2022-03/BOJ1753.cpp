#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2147483647

struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};

vector<pair<int, int>> adjacent[20001];
priority_queue<pair<int, int>,vector<pair<int,int>>,compare> pq;
int v, e;



void dijkstra(vector<int> distance) {	
	while (!pq.empty()) {
		int current = pq.top().first;	// Current vertex
		int cost = pq.top().second;	// Cost of current vertex
		pq.pop();

		for (int i = 0; i < adjacent[current].size(); i++) {
			int next = adjacent[current][i].first;	// Next vertex
			int next_cost = adjacent[current][i].second + cost;	// Sum of cost
			if (next_cost < distance[next]) {
				distance[next] = next_cost;
				pq.push({ next,next_cost });
			}
		}
	}

	for (int i = 0; i < v; i++) {
		if (distance[i + 1] == INF)
			cout << "INF" << '\n';
		else
			cout << distance[i + 1] << '\n';
	}
}

int main() {
	cin >> v >> e;

	int start;
	cin >> start;

	for (int i = 1; i <= e; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		adjacent[from].push_back({ to,weight });
		//adjacent[to].push_back({ from,weight });
	}
	

	vector<int> distance((v+1), INF);
	distance[start] = 0;

	pq.push({ start,distance[start]});
	dijkstra(distance);

	return 0;
}