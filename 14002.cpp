#include <iostream>
using namespace std;

int N;
int arr[1001];
int M[1001];
int P[1001];
int S[1001];
int len = 0;

void DP() {
	int low, high, mid, newL;

	for (int i = 0; i < N; i++) {
		low = 1;
		high = len + 1;

		while (low < high) {
			mid = low + ((high - low) / 2);
			if (arr[M[mid]] >= arr[i])
				high = mid;
			else
				low = mid + 1;
		}
		newL = low;
		P[i] = M[newL - 1];
		M[newL] = i;

		if (newL > len)
			len = newL;
	}

	int k = M[len];
	for (int j = len - 1; j >= 0; j--) {
		S[j] = arr[k];
		k = P[k];
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	DP();
	cout << len << "\n";

	for (int i = 0; i < len; i++) {
		cout << S[i] << " ";
	}

	return 0;
}