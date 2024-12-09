#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int n;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	n /= 4;
	for (int idx = 0; idx < n; idx++)
		cout << "long ";
	cout << "int";


	return 0;
}