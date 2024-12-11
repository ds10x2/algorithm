#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n; //의견의 개수
vector<int> v;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}
	for (int idx = 0; idx < n; idx++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int cnt = floor((float)n * 0.15 + 0.5);
	int score_sum = 0;

	for(int idx = cnt; idx < n - cnt; idx++) {
		score_sum += v[idx];
	}

	int result = floor((float)score_sum / (n - cnt * 2) + 0.5);
	cout << result;


	return 0;
}