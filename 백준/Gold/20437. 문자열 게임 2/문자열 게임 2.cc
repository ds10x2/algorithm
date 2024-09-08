/*

어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이
어떤 문자를 정확히 K개를 포함하고 문자열의 첫번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이

없으면 -1 출력

*/

#include <iostream>
#include <vector>
using namespace std;

string str;
int k;
char c;
int result1, result2;
int test_case;
vector<int> v[26];

int main() {

	cin >> test_case;
	for (int tc = 0; tc < test_case; tc++) {
		cin >> str >> k;

		result1 = 10001;
		result2 = 0;

		for (int idx = 0; idx < str.length(); idx++) {
			v[str[idx] - 'a'].push_back(idx);

			if (v[str[idx] - 'a'].size() >= k) {
				result1 = min(result1, idx - v[str[idx] - 'a'][v[str[idx] - 'a'].size() - k] + 1);
				result2 = max(result2, idx - v[str[idx] - 'a'][v[str[idx] - 'a'].size() - k] + 1);
			}
		}

		if (result1 != 10001 && result2 != 0)
			cout << result1 << " " << result2 << "\n";
		else
			cout << -1 << "\n";

		for (int idx = 0; idx < 26; idx++) {
			v[idx].clear();
		}
	}


	return 0;
}