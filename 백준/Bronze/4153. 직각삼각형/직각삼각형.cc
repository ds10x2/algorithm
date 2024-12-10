#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <utility>
using namespace std;

void sort_ascending(int& a, int& b, int& c) {
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
}


bool is_right_angle(int a, int b, int c) {
	if (c * c == (a * a) + (b * b)) return true;
	else return false;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);


	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		sort_ascending(a, b, c);
		if (is_right_angle(a, b, c)) cout << "right" << "\n";
		else cout << "wrong" << "\n";
	}


	return 0;
}