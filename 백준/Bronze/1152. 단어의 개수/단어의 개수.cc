#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string str;
	getline(cin, str);

	//문자열은 공백으로 시작하거나 끝날 수 있음
	//공백은 한 개로 구분되며 연속해서 나오지 않음

	int result = 0; //공백의 개수 저장

	if (str.length() == 1 && str[0] == ' ') {
		cout << 0;
		return 0;
	}

	for (int idx = 1; idx < str.length()-1; idx++) {
		if (str[idx] == ' ') result++;
	}

	cout << result + 1;


	return 0;
}