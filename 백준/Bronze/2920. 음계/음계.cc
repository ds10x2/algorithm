#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int arr[8];
bool flag;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int idx = 0; idx < 8; idx++)
		cin >> arr[idx];


	if (arr[0] == 1) flag = true; //ascending
	else if (arr[0] == 8) flag = false; //descending
	else {
		cout << "mixed" << "\n";
		return 0;
	}


	for (int idx = 1; idx < 8; idx++) {
		if (flag) {
			if (arr[idx - 1] + 1 == arr[idx]) continue;
			
			cout << "mixed" << "\n";
			return 0;
		}

		else {
			if (arr[idx - 1] - 1 == arr[idx]) continue;

			cout << "mixed" << "\n";
			return 0;
		}
	}

	if (flag) cout << "ascending" << "\n";
	else cout << "descending" << "\n";

	return 0;
}