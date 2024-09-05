#include <iostream>
#include <string>
using namespace std;

int N;

int grp(string str) {
	bool alph[27] = { false, };

	char c = str[0];
	alph[str[0] - 96] = true;
	for (int i = 1; i < str.length(); i++) {
		if (alph[str[i] - 96]&& c != str[i]) return 0;
		alph[str[i] - 96] = true;
		c = str[i];
	}
	return 1;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int result = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		result += grp(str);
		cout << str << " " << grp(str) << "\n";
	}

	cout << result;

	return 0;
}