#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
int m = 0;
int value[27];

bool comp(int x, int y) {
	return x > y;
}



int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int pow = 1;
		for (int j = str.length() - 1; j >= 0; j--) {
			value[str[j] - 64] += pow;
			pow *= 10;
		}
	}

	sort(value, value + 27, comp);


	int V = 9;
	int sum = 0;
	for(int i = 0; i < 27; i++) {
		if (value[i] == 0) break;

		sum += (value[i] * V);
		V--;
	}
	
	cout << sum;
	return 0;
}