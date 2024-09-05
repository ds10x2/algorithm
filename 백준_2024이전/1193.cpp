#include <iostream>
using namespace std;

int X;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> X;

	int k = 1;
	int sum;


	while (1) {	
		sum = k * (k + 1) / 2; //1부터 k까지의 합
		if (sum >= X)
			break;
		k++;
	}

	int result = sum - X;

	if (k % 2 == 0) {
		cout << k - result << "/" << 1 + result;
	}
	else {
		cout << 1 + result << "/" << k - result;
	}

	return 0;
}