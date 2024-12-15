#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int a, b;

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> a >> b;

	int result = gcd(a, b);

	cout << result << "\n" << (a * b) / result;

	return 0;
}