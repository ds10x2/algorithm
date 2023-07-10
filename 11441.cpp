#include <iostream>
using namespace std;

int N, M;
int num[100001];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	num[0] = 0;
	for (int i = 1; i < N+1; i++) {
		int n;
		cin >> n;

		num[i] = num[i-1] + n;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a1, a2;
		cin >> a1 >> a2;

		cout << num[a2] - num[a1 - 1] << "\n";
	}


	return 0;
}