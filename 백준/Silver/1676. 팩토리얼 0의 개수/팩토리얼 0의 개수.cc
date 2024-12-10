#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int num;
	cin >> num;


	int fact = 1;
	int cnt = 0;
	for (int n = 1; n <= num; n++) {

		fact *= n;

		while (fact % 10 == 0) {
			fact /= 10;
			cnt++;
		}

		fact = fact % 1000000;
	}

	cout << cnt << "\n";

	return 0;
}