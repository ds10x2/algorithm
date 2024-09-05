#include <iostream>
#include <string>
using namespace std;

string str, bomb;



int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> str >> bomb;

	string temp = "";

	int str_len = str.length();
	int bomb_len = bomb.length();

	for (int i = 0; i < str.length(); i++) {
		temp += str[i];
		if (temp.length() >= bomb_len) {
			bool flag = true;
			for (int j = 0; j < bomb_len; j++) {
				if (temp[temp.length() - bomb_len + j] != bomb[j]) {
					flag = false;
					break;
				}
			}

			if (flag)
				temp.erase(temp.end() - bomb_len, temp.end());
		}

	}

	if (temp.empty())
		cout << "FRULA";
	else
		cout << temp;


	return 0;
}