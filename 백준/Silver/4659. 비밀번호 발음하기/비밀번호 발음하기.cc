/*



*/

#include <iostream>
using namespace std;

string str;

bool is_vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

int main() {

	while (true) {

		cin >> str;

		if (str == "end") break;

		bool check = false;
		int vowel = 0; //연속된 모음 수
		int consonants = 0; //연속된 자음 수
		bool result = true;

		if (is_vowel(str[0])) {
			vowel++;
			check = true;
		}
		else {
			consonants++;
		}
		for (int idx = 1; idx < str.length(); idx++) {

			if (str[idx - 1] == str[idx] && str[idx] != 'e' && str[idx] != 'o') {
				result = false;
				break;
			}

			if (is_vowel(str[idx])) {
				vowel++;
				consonants = 0;
				check = true;
			}
			else {
				consonants++;
				vowel = 0;
			}
			if (vowel >= 3 || consonants >= 3) {
				result = false;
				break;
			}
		}
		if (check && result) cout << "<" << str << "> is acceptable." << "\n";
		else cout << "<" << str << "> is not acceptable." << "\n";
	}


	return 0;
}