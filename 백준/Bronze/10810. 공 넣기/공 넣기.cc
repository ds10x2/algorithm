#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int n, m;
int arr[101];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int idx = 0; idx < m; idx++) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int num = i; num <= j; num++)
			arr[num] = k;
	}

	for (int idx = 1; idx <= n; idx++)
		cout << arr[idx] << " ";



	return 0;
}