#include <iostream>
using namespace std;

int N;
int col[16]; //col[x]는 x번재 행에 있는 여왕말이 놓여 있는 열
int sum = 0;

bool promising(int x) {
	int k;
	bool Switch;

	k = 1;
	Switch = true;
	while (k < x && Switch) {
		if (col[x] == col[k] || abs(col[x] - col[k]) == x - k)
			Switch = false;
		k++;
	}

	return Switch;
}

void queens(int x) {
	if (promising(x)) {
		if (x == N) {
			sum++;
		}

		else{
			for (int i = 1; i <= N; i++) {
				col[x + 1] = i;
				queens(x + 1);
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	queens(0);
	cout << sum;

	return 0;
}