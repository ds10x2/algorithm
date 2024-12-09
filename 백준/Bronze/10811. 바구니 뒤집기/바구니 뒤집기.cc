#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int arr[101][2];
int idx;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int num = 1; num <= n; num++) {
		arr[num][0] = num;
	}


	for (int idx = 0; idx < m; idx++) {

		int i, j;
		cin >> i >> j;
		int cnt = 0;

		for (int num = 1; num <= n; num++) {
			if (num < i || num > j) arr[num][(idx + 1) % 2] = arr[num][idx % 2];
			else {
				arr[num][(idx + 1)% 2] = arr[j - cnt][idx % 2];
				cnt++;
			}
		}

	}

	for (int num = 1; num <= n; num++)
		cout << arr[num][m % 2] << " ";

	return 0;
}