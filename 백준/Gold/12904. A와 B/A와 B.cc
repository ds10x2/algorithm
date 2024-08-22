#include <iostream>
using namespace std;

/*
 12904 A와 B

 1. 문자열의 뒤에 A를 추가한다.
 2. 문자열을 뒤집고 뒤에 B를 추가한다.

 입력 받은 문자열에 대해 역순의 과정을 거친다.
 1. 문자열 맨 뒤에 있는 A를 제거한다
 2. 문자열 맨 뒤의 B를 제거하고 남은 문자열을 뒤집는다.


 문자열을 직접 뒤집지 않고 뒤집힌 여부를 판단하는 bool 타입의 변수를 사용한다.

*/

string str, new_str;
int isReverse; //초기값: 1 = 뒤집혀지지 않음, -1 = 뒤집힘
int str_len;
int idx;

// 문자열 비교 함수
void compare_str(string str2) {
	// cout << str2 << endl;
	int str2_idx = isReverse == -1 ? 0 : str2.length() - 1;
	// cout << str2_idx << endl;

	for (int str1_idx = 0; str1_idx < str.length(); str1_idx++) {
		// cout << str[str1_idx] << " " << str2_idx << " " << str2[str2_idx] << endl;
		if (str[str1_idx] != str2[str2_idx]) {
			cout << 0 << "\n";
			return;
		}
		str2_idx -= isReverse;
	}

	cout << 1 << "\n";
	return;
}

int make_str_same(string &s, int idx) {

	if (s[idx] == 'A') {
		idx += isReverse;
		str_len--;
		return idx;
	}
	else if (s[idx] == 'B') {
		idx += isReverse;
		str_len--;
		isReverse *= (-1);
		if (str_len < str.length()) {
			cout << 0 << "\n";
			return -1;
		}
		return idx;
	}
	else {
		cout << 0 << "\n";
		return -1;
	}
}


int main() {

	cin >> str >> new_str;

	str_len = new_str.length();

	isReverse = -1;
	int front_idx = 0;
	int back_idx = str_len - 1;
	
	while (str_len > 0) {

		if (isReverse == -1)
			back_idx = make_str_same(new_str, back_idx);
		else
			front_idx = make_str_same(new_str, front_idx);

		if (front_idx == -1 || back_idx == -1) return 0;

		
		if (str_len == str.length()) {
			compare_str(new_str.substr(front_idx, str.length()));
			return 0;
		}
		
	}


	return 0;
}