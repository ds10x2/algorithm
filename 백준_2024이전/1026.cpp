#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> a;
vector<int> b;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i < N+1; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (b[i] * a[N - 1 - i]);
	}

	cout << sum;

	return 0;
}