#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	int result = 0;
	while (n > 0) {
		result += n;
		n--;
	}

	cout << result;

	return 0;
}