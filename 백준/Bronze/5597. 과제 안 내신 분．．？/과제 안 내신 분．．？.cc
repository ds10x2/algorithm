#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

bool students[31];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int idx = 0; idx < 28; idx++) {
		int num;
		cin >> num;
		students[num] = true;
	}

	for (int idx = 1; idx <= 30; idx++) {
		if (!students[idx]) cout << idx << "\n";
	}


	return 0;
}