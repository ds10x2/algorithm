#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;



int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	for (int idx = 0; idx < n; idx++) {
		string str;
		cin >> str;
		cout << str[0] << str[str.length() - 1] << "\n";
	}

	return 0;
}