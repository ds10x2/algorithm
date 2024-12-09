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

	string str;
	cin >> str;

	int idx;
	cin >> idx;
	cout << str[idx - 1];

	return 0;
}