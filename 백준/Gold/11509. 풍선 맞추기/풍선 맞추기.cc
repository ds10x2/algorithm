#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005];
bool visited[1000005];
int max_value;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, x;
	cin >> n;
	for (int idx = 0; idx < n; idx++) {
		cin >> x;
		if (arr[x + 1] > 0) arr[x + 1]--;
		arr[x]++;
		if (max_value < x) max_value = x;
	}

	int result = 0;
	for (int idx = 1; idx <= max_value; idx++) result += arr[idx];
	cout << result;

	return 0;
}