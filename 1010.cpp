#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
int com[31];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		if (N == M) {
			cout << 1 << "\n";
			continue;
		}
		
		com[1] = M;

		for (int i = 2; i <= N; i++) {
			com[i] = com[i - 1] * (M - i + 1) / (i);
		}

		cout << com[N] << "\n";

	}


	return 0;
}