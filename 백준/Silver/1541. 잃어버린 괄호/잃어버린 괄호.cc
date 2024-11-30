#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

string str;
int result;
bool is_minus;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> str;
	string temp_str = "";
	int temp = 0;
	for (int idx = 0; idx <= str.length(); idx++) {
		if (str[idx] == '-' || str[idx] == '+' || idx == str.length()) {
			if (is_minus) result -= stoi(temp_str);
			else result += stoi(temp_str);
			temp_str = "";
		}
		else temp_str += str[idx];

		if (str[idx] == '-') is_minus = true;
	}

	cout << result;

	return 0;
}