#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int num;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int idx = 0; idx < 5; idx++) {
		int x;
		cin >> x;
		num += (x * x);
	}

	cout << num % 10;

	return 0;
}