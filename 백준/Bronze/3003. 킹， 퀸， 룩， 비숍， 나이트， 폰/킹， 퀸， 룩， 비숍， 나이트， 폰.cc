#include <iostream>
#include <algorithm>
using namespace std;

int arr[6] = { 1, 1, 2, 2, 2, 8 };

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int idx = 0; idx < 6; idx++) {
		int x;
		cin >> x;
		arr[idx] -= x;
	}


	for (int idx = 0; idx < 6; idx++)
		cout << arr[idx] << " ";


	return 0;
}