#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int test_case;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int a, b;
		cin >> a >> b;
		cout << "Case #" << tc <<": " << a + b << "\n";
	}




	return 0;
}