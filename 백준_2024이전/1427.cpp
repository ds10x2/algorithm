#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool com(int x, int y) {
	return x > y;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		v.push_back(str[i] - '0');

	sort(v.begin(), v.end(), com);

	for (int i = 0; i < str.length(); i++)
		cout << v[i];

	return 0;
}