#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

#define INF 1000000000

struct Cell {
	int x;
	int y;
	int num;
};

int n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[20][20];
int turn_max[5];

void Print_Board() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int Find_max() {
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (max_num < map[i][j])
				max_num = map[i][j];
		}
	}
	return max_num;
}

Cell Scan_Num(int row, int col, int dir_x, int dir_y) {
	while (map[row][col] == 0) {		
		row += dir_x;
		col += dir_y;
		if (row >= n || col >= n || row < 0 || col < 0) {
			row -= dir_x;
			col -= dir_y;
			break;
		}
	}
	return { row,col,map[row][col] };
}

void Move(int row, int col, int dir_x,int dir_y, int origin_num, int changed) {
	if (map[row][col] == 0) {
		Cell res = Scan_Num(row, col, dir_x, dir_y);
		if (res.num == 0) {

		}
		else {
			map[row][col] = res.num;
			map[res.x][res.y] = 0;
		}
	}
	else {
		Cell res = Scan_Num(row + dir_x, col + dir_y, dir_x, dir_y);
		if (res.num == 0) {

		}
		else {
			if (map[row][col] == res.num) {
				if (changed == 1) {
					map[res.x][res.y] = 0;
					map[row + dir_x][col + dir_y] = res.num;
				}
				else {
					changed = 1;
					map[row][col] = 2 * res.num;
					map[res.x][res.y] = 0;
				}
			}
			else {
				map[res.x][res.y] = 0;
				map[row+ dir_x][col + dir_y] = res.num;
			}
		}
	}

	if (origin_num == map[row][col])
		return;

	Move(row, col, dir_x, dir_y, map[row][col],changed);
}

void Left() {
	int dir_x = dx[0];
	int dir_y = dy[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Move(i, j, dir_x, dir_y, map[i][j],0);
		}
	}
}

void Up() {
	int dir_x = dx[2];
	int dir_y = dy[2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Move(i, j, dir_x, dir_y, map[i][j],0);
		}
	}
}

void Right() {
	int dir_x = dx[1];
	int dir_y = dy[1];
	for (int i = n-1; i >=0 ; i--) {
		for (int j = n-1; j >=0; j--) {
			Move(i, j, dir_x, dir_y, map[i][j],0);
		}
	}
}

void Down() {
	int dir_x = dx[3];
	int dir_y = dy[3];
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			Move(i, j, dir_x, dir_y, map[i][j],0);
		}
	}
}

void BT(int level) {
	if (level == 5) {
		return;
	}

	int max_temp;
	int map_temp[20][20];
	int map_size = 400;
	copy(&map[0][0], &map[0][0] + map_size, &map_temp[0][0]);
	Left();	
	max_temp = Find_max();
	if (turn_max[level] < max_temp)
		turn_max[level] = max_temp;	
	if (max_temp <= turn_max[level] / 2) {

	}
	else {
		BT(level + 1);
	}

	copy(&map_temp[0][0], &map_temp[0][0] + map_size, &map[0][0]);

	copy(&map[0][0], &map[0][0] + map_size, &map_temp[0][0]);
	Up();
	max_temp = Find_max();
	if (turn_max[level] < max_temp)
		turn_max[level] = max_temp;
	if (max_temp <= turn_max[level] / 2) {

	}
	else {
		BT(level + 1);
	}
	copy(&map_temp[0][0], &map_temp[0][0] + map_size, &map[0][0]);

	copy(&map[0][0], &map[0][0] + map_size, &map_temp[0][0]);
	Right();
	max_temp = Find_max();
	if (turn_max[level] < max_temp)
		turn_max[level] = max_temp;
	if (max_temp <= turn_max[level] / 2) {

	}
	else {
		BT(level + 1);
	}
	copy(&map_temp[0][0], &map_temp[0][0] + map_size, &map[0][0]);

	copy(&map[0][0], &map[0][0] + map_size, &map_temp[0][0]);
	Down();
	max_temp = Find_max();
	if (turn_max[level] < max_temp)
		turn_max[level] = max_temp;
	if (max_temp <= turn_max[level] / 2) {

	}
	else {
		BT(level + 1);
	}
	copy(&map_temp[0][0], &map_temp[0][0] + map_size, &map[0][0]);

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	BT(0);

	cout << turn_max[4];

	return 0;
}