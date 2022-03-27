#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

bool button[10];

int main() {
	int target;
	int m;
	int cnt = 0;
	int exit = 0;
	int distance = 0;

	fill(button, button+10, 1);

	cin >> target >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		button[temp] = 0;
	}


	int min_sub = 500000;
	int abs_sub;
	int temp;
	int current = -1;
	int loop = -1;

	distance = abs(target - 100);

	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			for (int c = 0; c < 10; c++) {
				for (int d = 0; d < 10; d++) {
					for (int e = 0; e < 10; e++) {
						for (int f = 0; f < 10; f++) {								
							loop++;
							if (button[0] == 0) {
								if (loop < 10) {
									if (button[f] == 0)
										continue;
									else {
										temp = 0;
										temp = a * 100000
											+ b * 10000
											+ c * 1000
											+ d * 100
											+ e * 10
											+ f * 1;

										abs_sub = abs(target - temp);
										if (abs_sub < min_sub) {
											min_sub = abs_sub;
											current = temp;
										}
									}
								}
								else if (loop < 100) {
									if (button[e] == 0 || button[f] == 0)
										continue;
									else {
										temp = 0;
										temp = a * 100000
											+ b * 10000
											+ c * 1000
											+ d * 100
											+ e * 10
											+ f * 1;

										abs_sub = abs(target - temp);
										if (abs_sub < min_sub) {
											min_sub = abs_sub;
											current = temp;
										}
									}
								}
								else if (loop < 1000) {
									if ( button[d] == 0 || button[e] == 0 || button[f] == 0)
										continue;
									else {
										temp = 0;
										temp = a * 100000
											+ b * 10000
											+ c * 1000
											+ d * 100
											+ e * 10
											+ f * 1;

										abs_sub = abs(target - temp);
										if (abs_sub < min_sub) {
											min_sub = abs_sub;
											current = temp;
										}
									}
								}
								else if (loop < 10000) {
									if ( button[c] == 0
										|| button[d] == 0 || button[e] == 0 || button[f] == 0)
										continue;
									else {
										temp = 0;
										temp = a * 100000
											+ b * 10000
											+ c * 1000
											+ d * 100
											+ e * 10
											+ f * 1;

										abs_sub = abs(target - temp);
										if (abs_sub < min_sub) {
											min_sub = abs_sub;
											current = temp;
										}
									}
								}
								else if (loop < 100000) {
									if (button[b] == 0 || button[c] == 0
										|| button[d] == 0 || button[e] == 0 || button[f] == 0)
										continue;
									else {
										temp = 0;
										temp = a * 100000
											+ b * 10000
											+ c * 1000
											+ d * 100
											+ e * 10
											+ f * 1;

										abs_sub = abs(target - temp);
										if (abs_sub < min_sub) {
											min_sub = abs_sub;
											current = temp;
										}
									}
								}
								else if (loop < 1000000) {
									if (button[a] == 0 || button[b] == 0 || button[c] == 0
										|| button[d] == 0 || button[e] == 0 || button[f] == 0)
										continue;
									else {
										temp = 0;
										temp = a * 100000
											+ b * 10000
											+ c * 1000
											+ d * 100
											+ e * 10
											+ f * 1;

										abs_sub = abs(target - temp);
										if (abs_sub < min_sub) {
											min_sub = abs_sub;
											current = temp;
										}
									}
								}
							}
							else if ( button[a] == 0 || button[b] == 0 || button[c] == 0
								|| button[d] == 0 || button[e] == 0 ||button[f] == 0)
								continue;
							else {
								temp = 0;
								temp = a * 100000
									+ b * 10000
									+ c * 1000
									+ d * 100
									+ e * 10
									+ f * 1;

								abs_sub = abs(target - temp);
								if (abs_sub < min_sub) {
									min_sub = abs_sub;
									current = temp;
								}
							}
						}
					}
				}
			}
		}
	}

	if (current == -1) {
		min_sub = abs(target - 100);
	}
	else {
		string current_str = to_string(current);

		cnt = current_str.size();
		min_sub += cnt;
	}

	if (distance < min_sub)
		cnt = distance;
	else
		cnt = min_sub;

	cout << cnt;

	return 0;
}