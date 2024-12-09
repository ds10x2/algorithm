#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int total;
int cnt;
int sum_price;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> total >> cnt;
	for (int idx = 0; idx < cnt; idx++) {
		int price, item_cnt;
		cin >> price >> item_cnt;
		sum_price += (price * item_cnt);
	}

	if (total == sum_price) cout << "Yes";
	else cout << "No";


	return 0;
}