#include <iostream>
using namespace std;

long long X, Y, Z;
long long low = 1;
long long high = 1000000000;
long long mid;

int search() {
	Z = (Y * 100) / X;

	if (Z >= 99)
		return -1;

	while (low <= high) {
		mid = (low + high) / 2;

		long long resultZ = (100 * (Y + mid)) / (X + mid);
		
		if (Z < resultZ) {
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return low;
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> X >> Y;

	int result = search();
	cout << result;


	return 0;
}