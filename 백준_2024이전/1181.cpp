#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> str[51];
int N;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		str[s.length()].push_back(s);
	}

	for (int i = 0; i < 51; i++) {
		sort(str[i].begin(), str[i].end());
		str[i].erase(unique(str[i].begin(), str[i].end()), str[i].end());
	}


	for (int i = 0; i < 51; i++)
		for (int j = 0; j < str[i].size(); j++)
			cout << str[i][j] << "\n";

	return 0;
}