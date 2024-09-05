#include <iostream>
#include <algorithm>
using namespace std;

int n;
int s = 0;

int bag(int num) {

	if (num % 5 == 0) {
		s += num / 5;
		return s;
	}
	else if (num - 3 >= 0) {
		s += 1;
		return bag(num - 3);
	}
	else
		return -1;

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	cout << bag(n);

	return 0;
}