#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9][9];
vector <pair<int, int>> point;
bool found = false;

bool check(int x, int y, int num) {

	for (int i = 0; i < 9; i++) {
		if (i != y && arr[x][i] == num)
			return false;
		if (i != x && arr[i][y] == num)
			return false;
	}

	int row = x / 3;
	int col = y / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != x && j != y && arr[row * 3 + i][col * 3 + j] == num)
				return false;
		}
	}

	return true;
}

void backtracking(int n) {
	if (n == point.size()) {
		found = true;
		return;
	}

	int x = point[n].first;
	int y = point[n].second;

	for (int i = 1; i <= 9; i++) {
		if (check(x, y, i)) {
			arr[x][y] = i;
			backtracking(n + 1);
		}
		if (found)
			return;
	}
	arr[x][y] = 0;
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				point.push_back({ i, j });
		}
	}


	backtracking(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}