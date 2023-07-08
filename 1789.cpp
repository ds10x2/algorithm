#include <iostream>
using namespace std;

long long S;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> S;

	long long n = 1;
	long long s = n * (n + 1) / 2;

	while (s <= S) {
		n++;
		s = n * (n + 1) / 2;
	}

	cout << n - 1;

	return 0;
}