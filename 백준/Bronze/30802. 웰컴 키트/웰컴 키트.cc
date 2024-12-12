#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int t_size[6];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);


	int n;
	cin >> n;

	int t_bundle = 0;
	for (int idx = 0; idx < 6; idx++) {
		cin >> t_size[idx];
	}

	int t, p;
	cin >> t >> p;


	for (int idx = 0; idx < 6; idx++) {
		t_bundle += (t_size[idx] / t + (t_size[idx] % t > 0));
	}

	cout << t_bundle << "\n";
	cout << n / p << " " << n % p << "\n";


	return 0;
}