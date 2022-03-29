#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 800*1000
using namespace std;

int n, e;
int v1, v2;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

vector<pair<int, int>> adjacent[801];
priority_queue<pair<int, int>,vector<pair<int,int>>,compare> pq;
vector<long> d1(801, INF);
vector<long> d2(801, INF);
vector<long> d3(801, INF);



void dijkstra(vector<long> &distance) {
	while (!pq.empty()) {
		int current = pq.top().first;
		long cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < adjacent[current].size(); i++) {
			int next = adjacent[current][i].first;
			long next_cost = cost + adjacent[current][i].second;
			if (next_cost < distance[next]) {
				distance[next] = next_cost;
				pq.push({ next,next_cost });
			}
		}
	}

}

int main() {
	cin >> n >> e;

	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adjacent[a].push_back({ b,c });
		adjacent[b].push_back({ a,c });
	}

	cin >> v1 >> v2;

	int start = 1;
	int start_cost = 0;
	d1[start] = start_cost;
	pq.push({ start,start_cost});
	dijkstra(d1);

	//for (int i = 0; i < n; i++) {
	//	cout << d1[i + 1] << ' ';
	//}
	//cout << '\n';

	start = n;
	start_cost = 0;
	d2[start] = start_cost;
	pq.push({ start,start_cost });
	dijkstra(d2);

	start = v1;
	start_cost = 0;
	d3[start] = start_cost;
	pq.push({ start,start_cost });
	dijkstra(d3);

	long start_v1 = d1[v1];
	long start_v2 = d1[v2];
	long v1_end = d2[v1];
	long v2_end = d2[v2];
	long v1_v2 = d3[v2];
	long v2_v1 = d3[v2];

	long root1 = start_v1 + v1_v2 + v2_end;
	long root2 = start_v2 + v2_v1 + v1_end;

	if (start_v1 == INF || v1_v2 == INF || v2_end == INF
		&& start_v2 == INF || v2_v1 == INF || v1_end == INF)
		cout << "-1";
	else if (root1 < root2)
		cout << root1;
	else
		cout << root2;

	return 0;
}