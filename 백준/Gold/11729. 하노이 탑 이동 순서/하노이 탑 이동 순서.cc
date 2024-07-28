/*

백준 11729 하노이 탑 이동 순서



*/


#include <iostream>
#include <algorithm>
using namespace std;

int n;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
	}
	else {
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << "\n";
		hanoi(n - 1, by, from, to);
	}
}

int hanoi_cnt(int n) {
	if (n == 1) return 1;
	return 2 * hanoi_cnt(n - 1) + 1;

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	cout << hanoi_cnt(n) << "\n";
	hanoi(n, 1, 2, 3);

	return 0;
}