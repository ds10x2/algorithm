#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v, back;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int x;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
		back.push_back(x);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(v.begin(), v.end(), back[i]) - v.begin() << " ";
	}

	return 0;
}