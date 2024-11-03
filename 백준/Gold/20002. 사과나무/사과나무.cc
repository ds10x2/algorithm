#include <iostream>
#include <algorithm>
using namespace std;

int n;
int result = -1001;
int arr[301][301];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	for (int row = 1; row <= n; row++)
		for (int col = 1; col <= n; col++) {
			int apple;
			cin >> apple;
			arr[row][col] = apple + arr[row - 1][col] + arr[row][col - 1] - arr[row - 1][col - 1];
		}

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			int k = 1;
			while ((row - k >= 0) && (col - k >= 0)) {
				result = max(result, arr[row][col] - arr[row - k][col] - arr[row][col - k] + arr[row - k][col - k]);
				k++;
			}
		}
	}
	cout << result;

	return 0;
}