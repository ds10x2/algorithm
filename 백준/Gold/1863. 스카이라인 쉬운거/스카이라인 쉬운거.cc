/*

백준 1863 스카이라인 쉬운거


*/



#include <iostream>
#include <stack>
using namespace std;

int n;
int x, y;
stack<int> s;
int result;

int main() {

	cin >> n;
	for (int idx = 0; idx < n; idx++) {
		cin >> x >> y;

		if (!s.empty() && s.top() > y) {
			while (!s.empty() && s.top() > y) {
				s.pop();
				result++;
			}
				if (s.empty() && y != 0) {
					s.push(y);
				}
				else if (!s.empty() && s.top() < y)
					s.push(y);
		}
		else if (!s.empty() && s.top() < y) {
			s.push(y);
		}
		else if (!s.empty() && s.top() == y) {
			cout << 2 << endl;
			result++;
		}
		else {
			if(y != 0)
				s.push(y);
		}
	}

	cout << result + s.size()<< endl;

	return 0;
}
