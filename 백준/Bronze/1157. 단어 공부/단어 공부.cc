#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int arr[26];
pair<char, int> result = { ' ', 0};

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string str;
	cin >> str;

	bool flag = false;
	for (int idx = 0; idx < str.length(); idx++) {
		char alpha = toupper(str[idx]);
		arr[alpha - 'A']++;

		if (result.second < arr[alpha - 'A']) {
			result = { alpha, arr[alpha - 'A'] };
			flag = false;
		}
		else if (result.second == arr[alpha - 'A']) {
			flag = true;
		}
	}

	if (flag) cout << "?";
	else cout << result.first;


	return 0;
}