#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string s;
	cin >> s;
	
	sort(s.begin(), s.end(), greater<>());
	if (s[s.length() - 1] != '0')
		cout << -1;
	else {
		long long sum = 0;
		for (auto o : s) {
			sum += o - '0';
		}
		if (sum % 3 == 0)
			cout << s;
		else cout << -1;
	}

	return 0;
}