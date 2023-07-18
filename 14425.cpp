#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, int> m;
int cnt = 0;


int main(){
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		m[str]++;
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (m[str] == 1) cnt++;
	}

	cout << cnt;

	return 0;
}