#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, k;
int cnt;
string s;
vector<char> v;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> k >> s;

	for (int i = 0; i < s.length(); i++) {
		while (k > 0 && !v.empty() && v.back() < s[i]) {
			v.pop_back();
			k--;
		}
		v.push_back(s[i]);
	}

	while (k--) {
		v.pop_back();
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}

	return 0;
}