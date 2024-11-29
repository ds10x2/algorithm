#include <iostream>
#include <stack>
using namespace std;

int N; //학생들의 수

stack<int> s;

int main() {

	cin >> N;
	int now = 1;
	for (int idx = 0; idx < N; idx++) {
		int num;
		cin >> num;

		if (num == now) {
			now++;
		}
		else s.push(num);

		while (!s.empty() && s.top() == now) {
			s.pop();
			now++;
		}
	}

	if (s.empty()) cout << "Nice";
	else cout << "Sad";
	
	return 0;
}