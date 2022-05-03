#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

#define INF	2147483647
typedef pair<pair<int, int>, double> edge;
typedef pair<double, double> point;
struct compare {
	bool operator()(edge a, edge b) {
		return a.second > b.second;
	}
};
vector<point> star;
priority_queue<edge, vector<edge>, compare> Edges;
int n;
int parent[101];
double MST_cost;

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	int x_p = findParent(x);
	int y_p = findParent(y);
	if (x_p < y_p)
		parent[y_p] = parent[x_p];
	else
		parent[x_p] = parent[y_p];
}

bool isCycle(int x, int y) {
	int x_p = findParent(x);
	int y_p = findParent(y);
	if (x_p == y_p)
		return 1;
	else
		return 0;
}

void Kruskal() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (!Edges.empty()) {
		int start = Edges.top().first.first;
		int end = Edges.top().first.second;
		double cost = Edges.top().second;
		Edges.pop();

		if (isCycle(start, end) == 0) {
			unionParent(start, end);
			MST_cost += cost;
		}
	}

	cout << MST_cost;
}

double distance(point a, point b) {
	double dx = abs(a.first - b.first);
	double dy = abs(a.second - b.second);
	return sqrt(dx * dx + dy * dy);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		point a;
		double x, y;
		cin >> x >> y;
		a.first = x;
		a.second = y;
		star.push_back(a);
	}

	for (int i = 0; i < star.size(); i++) {
		for (int j = i; j < star.size(); j++) {
			if (i != j) {
				double dist = distance(star[i], star[j]);
				Edges.push({ {i+1,j+1},dist });
			}
		}
	}

	Kruskal();


	return 0;
}