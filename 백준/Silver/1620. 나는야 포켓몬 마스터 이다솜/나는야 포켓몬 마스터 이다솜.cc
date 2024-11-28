#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<string> pokemon_list;
map<string, int> pokemon_num;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int idx = 1; idx <= n; idx++) {
		string name;
		cin >> name;
		pokemon_list.push_back(name);
		pokemon_num[name] = idx;
	}

	for (int idx = 0; idx < m; idx++) {
		string input;
		cin >> input;

		if (input[0] >= '0' && input[0] <= '9') cout << pokemon_list[stoi(input) - 1] << "\n";
		else cout << pokemon_num[input] << "\n";
	}


	return 0;
}