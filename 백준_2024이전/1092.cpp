#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> c;
vector<int> box;
int max_crane;
int t;

bool com(int a, int b) {
	return a > b;
}

void input() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		c.push_back(x);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		box.push_back(x);
	}

	sort(c.begin(), c.end(), com);
	sort(box.begin(), box.end(), com);

	max_crane = c[0];
}

void solution() {

	int c_num = 0;
	int idx = 0;

	while (!box.empty()) {

		if (box[idx] > max_crane) {
			t = -1;
			return;
		}

		if (box[idx] <= c[c_num]) {
			box.erase(box.begin() + idx);
			c_num++;
		}
		else idx++;

		if (c_num == n || idx >= box.size()) {
			t++;
			c_num = 0;
			idx = 0;
		}

		
	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();
	solution();

	cout << t;

	return 0;
}