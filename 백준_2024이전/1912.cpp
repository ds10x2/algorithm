#include <iostream>
using namespace std;

int n;
int num[100001];
int r[100001];
int m;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	num[0] = 0;

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> num[i];
	}
	
	r[0] = 0;
	r[1] = num[1];
	m = num[1];
	for (int i = 2; i < n+1; i++) {
		r[i] = num[i];
		if (r[i] < r[i - 1] + num[i]) {
			r[i] = r[i - 1] + num[i];
		}
		if (r[i] > m) m = r[i];

	}
	cout << m;

	return 0;
}