#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

vector<int> v;



int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int num_sum = 0;

	for (int idx = 0; idx < 5; idx++) {
		int x;
		cin >> x;
		v.push_back(x);
		num_sum += x;
	}

	sort(v.begin(), v.end());

	cout << num_sum / 5 << "\n" << v[2];

	return 0;
}