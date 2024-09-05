#include <iostream>
#include <stack>
using namespace std;


int N;
stack<pair<int, int>> s;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	s.push({ 100000001, 0 });

	cin >> N;


	for (int i = 1; i < N + 1; i++) {
		int x;
		cin >> x;
		while (s.top().first < x) {
			s.pop();
		}
		cout << s.top().second << " ";
		s.push({ x, i });
	}



	return 0;
}