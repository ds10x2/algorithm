/*



*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string str;
stack<char> st;


int main() {

	cin >> str;

	int cnt = 0;
	for (int idx = 0; idx < str.length(); idx++) {
		if (str[idx] == 'P') {
			st.push('P');
			cnt++;
		}
		else if (str[idx] == 'A') {
			if (cnt >= 2 && str[idx + 1] == 'P') {
				//PP제거
				st.pop();
				st.pop();
				st.push('P');
				cnt--;
				idx++;
			}
			else {
				st.push('A');
			}
		}
	}

	string result = "";
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	reverse(result.begin(), result.end());

	if (result == "PPAP" || result == "P") {
		cout << "PPAP" << endl;
	}
	else
		cout << "NP" << endl;

	return 0;
}