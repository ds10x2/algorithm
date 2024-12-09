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

	int x;
	cin >> x;
	string str = "UOS";
	cout << str[(x-1) % 3];

	return 0;
}