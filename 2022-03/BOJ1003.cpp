#include <iostream>
using namespace std;

int callCount[40][2];


pair<int,int> fibonacci(int n) {
    if (callCount[n][0] != 0 || callCount[n][1] != 0) {
        return pair<int, int>(callCount[n][0], callCount[n][1]);
    }

    if (n == 0) {
        //printf("0");
        return pair<int, int>(1, 0);

    }
    else if (n == 1) {
        //printf("1");
        return pair<int, int>(0, 1);
    }
    else {
        int f1 = fibonacci(n - 1).first;
        int s1 = fibonacci(n - 1).second;
        int f2 = fibonacci(n - 2).first;
        int s2 = fibonacci(n - 2).second;
        callCount[n][0] = f1 + f2;
        callCount[n][1] = s1 + s2;
        return pair<int, int>(f1 + f2, s1 + s2);

    }
}

int main() {
	callCount[0][0] = {1};
	callCount[1][1] = {1};

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
        fibonacci(n);
        cout << callCount[n][0] << ' ' << callCount[n][1] << '\n';
	}

    return 0;
}