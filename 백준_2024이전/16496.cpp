#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
string s[1001];

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	
	sort(s, s + N, cmp);

	if (s[0] == "0") {
		cout << "0";
		return 0;
	}

	string result;
	for (int i = 0; i < N; i++) {
		result += s[i];
	}

	cout << result;



	return 0;
}