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
	for (int tc = 0; tc < test_case; tc++) {
		int h, w, n;
		cin >> h >> w >> n;

		int result = ((n - 1) / h + 1) + (((n - 1) % h + 1) * 100);
		cout << result << "\n";
	}

	return 0;
}