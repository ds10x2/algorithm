#include <iostream>
#include <algorithm>
using namespace std;

int N;
int t[16];
int p[16];
int result[16] = { 0, };

void dp() {

	int deadline;
	for (int i = N; i > 0; i--) {
		deadline = i + t[i];
		if (deadline > N + 1) {
			result[i] = result[i + 1];
		}
		else {
			result[i] = max(result[i + 1], result[deadline] + p[i]);
		}
	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> p[i];

	}
	dp();

	cout << result[1];
	

	return 0;
}