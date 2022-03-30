#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

deque<int> dq;
string ans[100];

bool funtion(string work, deque<int>& dq, bool *isReverse) {
	for (int i = 0; i < work.size(); i++) {
		if (work[i] == 'R') {
			if (*isReverse == 1)
				*isReverse = 0;
			else
				*isReverse = 1;
		}
		if (work[i] == 'D') {
			if (dq.size() == 0) {
				cout << "error\n";
				return true;
			}
			if (*isReverse == 1) {
				dq.pop_back();
			}
			else {
				dq.pop_front();
			}
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string work;
		int n;
		string arr_int;
		int temp = 0;
		cin >> work >> n >> arr_int;

		for (int j = 0; j < arr_int.size(); j++) {
			if (n == 0)
				break;
			if (isdigit(arr_int[j])) {
				temp++;
				dq.push_back(arr_int[j] - 48);
				if (temp == 2) {
					int x = dq.back();
					dq.pop_back();
					int y = dq.back();
					dq.pop_back();
					dq.push_back(10 * y + x);
				}
				else if (temp == 3) {
					int x = dq.back();
					dq.pop_back();
					int y = dq.back();
					dq.pop_back();
					dq.push_back(10 * y + x);
				}
			}
			else {
				temp = 0;
			}
		}

		bool isReverse = 0;
		int isError = funtion(work, dq, &isReverse);
		
		if (isError == 1) {
			// Do nothing
		}
		else {
			cout << '[';
			if (isReverse == 0) {
				for (int i = 0; i < dq.size(); i++) {
					if (dq.size() == 1)
						cout << dq[i];
					else if (dq.size() != 1) {
						if (i == dq.size() - 1) {
							cout << dq[i];
						}
						else {
							cout << dq[i] << ',';
						}
					}
				}
			}
			else {
				for (int i = 0; i < dq.size(); i++) {
					if (dq.size() == 1)
						cout << dq[dq.size() - i -1];
					else if (dq.size() != 1) {
						if (i == dq.size()-1) {
							cout << dq[dq.size() - i - 1];
						}
						else {
							cout << dq[dq.size() - i - 1] << ',';
						}
					}
				}
			}
			cout << ']' << '\n';
		}

		dq.clear();
	}
}