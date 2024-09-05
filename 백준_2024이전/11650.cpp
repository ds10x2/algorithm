#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> num;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;

		cin >> x >> y;
		num.push_back({ x, y });
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < N; i++) {
		cout << num[i].first << " " << num[i].second << "\n";
	}


	return 0;
}