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

	int a, b, c;
	cin >> a >> b >> c;
	cout << a + b - c << "\n";
	cout << stoi(to_string(a) + to_string(b)) - c << "\n";

	return 0;
}