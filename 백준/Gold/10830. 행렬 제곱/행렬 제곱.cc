#include <iostream>
#include <algorithm>
using namespace std;

long long N, B;
long long matrix[5][5];
long long result[5][5];

void multi_matrix(long long matrix1[5][5], long long matrix2[5][5]) {
	long long tmp[5][5];

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			long long sum = 0;

			for (int idx = 0; idx < N; idx++) {
				sum += matrix1[row][idx] * matrix2[idx][col];
			}

			tmp[row][col] = sum % 1000;
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			matrix1[row][col] = tmp[row][col];
		}
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> B;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> matrix[row][col];
		}
		result[row][row] = 1;
	}

	while (B > 0) {
		if (B % 2 == 1)
			multi_matrix(result, matrix);

		multi_matrix(matrix, matrix);
		B /= 2;
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cout << result[row][col] << " ";
		}
		cout << "\n";
	}

	return 0;
}