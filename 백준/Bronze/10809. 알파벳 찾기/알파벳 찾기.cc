#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

int arr[26];


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string str;
	cin >> str;
	for (int idx = 0; idx < str.length(); idx++) {
		int alpha = str[idx] - 'a';

		if (arr[alpha] == 0) arr[alpha] = idx + 1;
	}

	for (int idx = 0; idx < 26; idx++) {
		cout << arr[idx] -1 << " ";
	}

	return 0;
}