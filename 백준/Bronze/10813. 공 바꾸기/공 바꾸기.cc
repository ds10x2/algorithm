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
	for (int num = 1; num <= n; num++) arr[num] = num;

	for (int idx = 0; idx < m; idx++) {
		int i, j;
		cin >> i >> j;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	for (int num = 1; num <= n; num++)
		cout << arr[num] << " ";


	return 0;
}