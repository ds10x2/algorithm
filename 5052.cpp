#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int t;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<string> phone;
		bool flag = false;
		for (int j = 0; j < n; j++) {
			string str;
			cin >> str;
			phone.push_back(str);
		}

		sort(phone.begin(), phone.end());

		for (int k = 0; k < phone.size() - 1; k++) {
			string current = phone[k];
			string next = phone[k + 1];

			if (current.length() >= next.length()) continue;

			if (current == next.substr(0, current.length())) {
				flag = true;
				break;
			}

		}

		if (flag) cout << "NO\n";
		else cout << "YES\n";

	}

	return 0;
}