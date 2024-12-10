#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int num;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> num;
	for (int idx = 1; idx <= num; idx++) {
		cout << idx << "\n";
	}

	return 0;
}