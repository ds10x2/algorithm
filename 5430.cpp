#include <iostream>
#include <deque>
using namespace std;

int T;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;

		int num;
		cin >> num;

		deque<int> dq;

		char c;
		cin >> c; //'['입력받기
		int t = 0;

		while (1) {
			cin >> c;
			if (c == ']')
				break;

			if (c == ',')
				t = 0;
			else {
				if (t == 0) {
					dq.push_back(c - '0');
					t++;
				}
				else {
					int n = dq.back();
					dq.pop_back();
					n = n * 10 + (c - '0');
					dq.push_back(n);
				}
			}
		}


		bool rev = false;
		bool err = false;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'R') {
				if (rev) rev = false;
				else rev = true;
			}
			else if (str[j] == 'D') {
				if (num == 0) {
					err = true;
					break;
				}
				if (rev) dq.pop_back();
				else dq.pop_front();

				num--;
			}
		}

		if (err) cout << "error" << "\n";
		else {
			cout << "[";
			if (!rev) {
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					
					if(!dq.empty()) cout << ",";
				}
			}
			else {
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();

					if (!dq.empty()) cout << ",";
				}
			}
			cout << "]" << "\n";
		}

	}



	return 0;
}