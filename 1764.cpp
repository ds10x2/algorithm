#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, M;

//vector<string> v[27];
vector<string> name;
map<string, int> m;

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

		m[str]++;
		if (m[str] > 1)
			name.push_back(str);
	}

	sort(name.begin(), name.end());

	cout << name.size() << "\n";
	for (int i = 0; i < name.size(); i++)
		cout << name[i] << "\n";

	return 0;
}