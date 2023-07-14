#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}