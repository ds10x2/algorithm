#include <iostream>
using namespace std; 

int arr[10001];

void findPost(int start, int end) {
	if(start >= end)
		return;

	if (start == end - 1) {
		cout << arr[start] << "\n";
		return;
	}

	int idx = start + 1;
	while (idx < end) {
		if (arr[start] < arr[idx]) {
			break;
		}
		idx++;
	}
	findPost(start + 1, idx);
	findPost(idx, end);
	cout << arr[start] << "\n";
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	int index = 0;
	while (cin >> n) {
		if (n == EOF) break;
		arr[index++] = n;
	}

	findPost(0, index);



	return 0;
}