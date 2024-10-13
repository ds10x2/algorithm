#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001][1001];
char num;
int result;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int row = 1; row <= n; row++)
		for (int col = 1; col <= m; col++) {
			cin >> num;
			arr[row][col] = num - '0';
		}

	
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= m; col++) {
			if (arr[row][col] == 1) {
				arr[row][col] = min(min(arr[row][col - 1], arr[row - 1][col]), arr[row - 1][col - 1] ) + 1;
				result = max(result, arr[row][col]);
			}
		}
	}

	cout << result * result << endl;


	return 0;
}