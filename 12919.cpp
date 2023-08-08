#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, t;
string tmp;
int result = 0;

void makeT(string S, string T) {
	

	if (S == T) {
		result = 1;
		return;
	}

	if (S.length() >= T.length())
		return;

	if (T[T.length() - 1] == 'A') {
		tmp = T;
		tmp.erase(tmp.length() - 1);
		makeT(S, tmp);
	}
	if (T[0] == 'B') {
		tmp = T;
		tmp.erase(tmp.begin());
		reverse(tmp.begin(), tmp.end());
		makeT(S, tmp);
	}


}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> s >> t;

	makeT(s, t);

	cout << result;
	return 0;
}