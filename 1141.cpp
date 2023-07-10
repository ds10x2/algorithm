#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> str;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		str.push_back(input);
	}

	int cnt = N;

	sort(str.begin(), str.end());

	for (int i = 0; i < N - 1; i++) {
		string current = str[i];
		string next = str[i + 1];

		if (current > next) continue;

		if (current == next.substr(0, current.length()))
			cnt--;
	}

	cout << cnt;


	return 0;
}