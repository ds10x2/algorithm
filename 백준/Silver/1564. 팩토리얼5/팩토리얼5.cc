/*

백준 1564



*/


#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	
	int n;
	cin >> n;
	
	int cnt = 0;
	
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;

		while (result % 10 == 0) {
			result /= 10;
		}

		result %= 1000000000000;
	}


	if (result >= 100000) cnt = 5;
	else if (result >= 10000) cnt = 4;
	else if (result >= 1000) cnt = 3;
	else if (result >= 100) cnt = 2;
	else if (result >= 10) cnt = 1;


	cout.width(cnt);
	cout.fill('0');
	cout << (result % 100000);

	return 0;
}