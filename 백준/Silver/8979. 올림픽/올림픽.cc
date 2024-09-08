/*



*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt, country, idx;
int gold, silver, bronze;
pair<pair<int, pair<int, int>>, int> arr[1001];

bool comp(pair<pair<int, pair<int, int>>, int> a, pair<pair<int, pair<int, int>>, int> b) {
	if (a.first.first != b.first.first) 
		return a.first.first > b.first.first;
	
	if (a.first.second.first != b.first.second.first) 
		return a.first.second.first > b.first.second.first;
	
	return a.first.second.second > b.first.second.second;

}


int main() {

	cin >> cnt >> country;
	for (int i = 0; i < cnt; i++) {
		cin >> idx >> gold >> silver >> bronze;
		arr[idx] = { {gold, {silver, bronze} }, idx };
	}


	sort(arr + 1, arr + cnt + 1, comp);


	int tmp = 0;
	if (arr[1].second == country) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 2; i <= cnt; i++) {

		if (arr[i - 1].first.first != arr[i].first.first
			|| arr[i - 1].first.second.first != arr[i].first.second.first
			|| arr[i - 1].first.second.second != arr[i].first.second.second)
			tmp = i;

		if (arr[i].second == country)
			cout << tmp << endl;
	}
	

	return 0;
}