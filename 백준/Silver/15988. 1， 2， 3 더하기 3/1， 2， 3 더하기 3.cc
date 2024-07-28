/*

백준 15988 1, 2, 3 더하기 3

<입력>
테스트 케이스 수
정수




*/


#include <iostream>
#include <algorithm>
using namespace std;

long arr[1000001];


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	int tc;
	cin >> tc;

	int max_idx = 3;

	for (int t = 0; t < tc; t++) {

		int n;
		cin >> n;

		if (n > max_idx) {

			for (int idx = max_idx + 1; idx <= n; idx++) {
				arr[idx] = (arr[idx - 3] + arr[idx - 2] + arr[idx - 1]) % 1000000009;
			}

			max_idx = n;
		}
		cout << arr[n] << endl;;
	}
	return 0;
}