#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

int n;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	int result = 0;
	for (int idx = 0; idx < n; idx++) {
		char c;
		cin >> c;
		result += (c - '0');
	}

	cout << result;


	return 0;
}