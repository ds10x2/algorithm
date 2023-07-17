#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int num[10] = { 0, };

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int x = str[i] - '0';
		num[x]++;
	}

	int m = (num[6] + num[9]) / 2;
	cout << m << " ";
	if ((num[6] + num[9]) % 2 == 1) m++;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9)continue;
		if (m < num[i]) m = num[i];
	}

	cout << m;

	return 0;
}