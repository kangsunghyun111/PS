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
typedef pair<pair<int, int>, int> edge;

struct compare {
	bool operator()(edge a, edge b) {
		return a.second > b.second;
	}
};

struct planet {
	int id;
	int x;
	int y;
	int z;
	planet(int a, int b, int c, int d) : x(a), y(b), z(c),id(d) {}
};

int tunnel_cost(planet a, planet b, char flag) {
	int x = abs(a.x - b.x);
	int y = abs(a.y - b.y);
	int z = abs(a.z - b.z);
	if (flag == 'x')
		return x;
	if (flag == 'y')
		return y;
	if (flag == 'z')
		return z;
}

vector<planet> planets;


bool comp_x(planet a, planet b) {
	return a.x > b.x;
}
bool comp_y(planet a, planet b) {
	return a.y > b.y;
}
bool comp_z(planet a, planet b) {
	return a.z > b.z;
}

int n;
priority_queue<edge, vector<edge>, compare> node;
int parent[100001];
int answer;

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	int a = findParent(x);
	int b = findParent(y);
	if (a < b)
		parent[b] = parent[a];
	else
		parent[a] = parent[b];
}

bool isCycle(int x, int y) {
	int a = findParent(x);
	int b = findParent(y);
	if (a == b)
		return 1;
	else
		return 0;
}

void Kruskal() {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	while (!node.empty()) {
		int start = node.top().first.first;
		int end = node.top().first.second;
		int cost = node.top().second;
		node.pop();

		if (isCycle(start, end) == 0) {
			unionParent(start, end);
			answer += cost;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		planet a(x, y, z, i);
		planets.push_back(a);
	}

	sort(planets.begin(), planets.end(),comp_x);
	for (int i = 0; i < n - 1; i++) {
		int cost = tunnel_cost(planets[i], planets[i + 1],'x');
		node.push({ {planets[i].id,planets[i + 1].id},cost });
	}
	sort(planets.begin(), planets.end(), comp_y);
	for (int i = 0; i < n - 1; i++) {
		int cost = tunnel_cost(planets[i], planets[i + 1],'y');
		node.push({ {planets[i].id,planets[i + 1].id},cost });
	}
	sort(planets.begin(), planets.end(), comp_z);
	for (int i = 0; i < n - 1; i++) {
		int cost = tunnel_cost(planets[i], planets[i + 1],'z');
		node.push({ {planets[i].id,planets[i + 1].id},cost });
	}

	Kruskal();

	cout << answer;

	return 0;
}