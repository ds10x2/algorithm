#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int idx = 1; idx <= n; idx++) {
		for (int star = 1; star <= idx; star++) cout << "*";
		for (int blank = 0; blank < n - idx; blank++)cout << " ";
		for (int blank = 0; blank < n - idx; blank++)cout << " ";
		for (int star = 1; star <= idx; star++) cout << "*";
		cout << "\n";
	}
	for (int idx = 1; idx <= n; idx++) {
		for (int star = 1; star <= n - idx; star++) cout << "*";
		for (int blank = 0; blank < idx; blank++)cout << " ";
		for (int blank = 0; blank < idx; blank++)cout << " ";
		for (int star = 1; star <= n - idx; star++) cout << "*";
		cout << "\n";
	}

	return 0;
}