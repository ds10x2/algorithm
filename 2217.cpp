#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int w;
		cin >> w;
		v.push_back(w);
	}

	sort(v.begin(), v.end());

	int result = v[0] * N;

	for (int i = 1; i < N; i++) {
		int temp = v[i] * (N - i);
		if (result < temp) {
			result = temp;
		}
		else continue;
		
	}

	cout << result;

	return 0;
}