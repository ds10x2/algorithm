#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> num;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		num.push_back(x);
	}
	
	sort(num.begin(), num.end());

	num.erase(unique(num.begin(), num.end()), num.end());

	for (int i = 0; i < num.size(); i++)
		cout << num[i] << " ";


	return 0;
}