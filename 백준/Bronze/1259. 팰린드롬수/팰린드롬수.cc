#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);



	string str = "";

	while (true) {
		cin >> str;
		if (str == "0") break;

		bool flag = true;
		for (int idx = 0; idx < str.length() / 2; idx++) {
			if (str[idx] != str[str.length() - idx - 1]) {
				flag = false;
				break;
			}
		}

		if (flag) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}

	return 0;
}