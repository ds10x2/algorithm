#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int factorial(int n) {
	if (n == 1 || n == 0)
		return 1;
	
	return factorial(n - 1) * n;
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	cout << factorial(n) / (factorial(k) * factorial(n - k));

	return 0;
}