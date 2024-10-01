#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

/*

백준 1806번 부분합

*/

int N;
int arr[100001];
int sum;

int st, ed, s;
int result = 100001;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> sum;
	for (int idx = 0; idx < N; idx++)
		cin >> arr[idx];
	
	st = 0;
	ed = 0;
	s = 0;

	while (st <= ed) {
		if (s >= sum) {
			result = min(result, ed - st);
			s -= arr[st++];
		}
		else if (ed == N) break;
		else s += arr[ed++];
	}

	if (result == 100001) cout << 0 << "\n";
	else cout << result << "\n";

	return 0;
}