#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	int cnt;
	string str;
	
	cin >> n;
	for (int tc = 0; tc < n; tc++) {
		cin >> cnt >> str;

		for (int idx = 0; idx < str.length(); idx++)
			for (int cnt_idx = 0; cnt_idx < cnt; cnt_idx++)
				cout << str[idx];
		cout << "\n";
	}

	return 0;
}