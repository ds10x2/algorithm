#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> member[100001]; //부하직원 저장
int scr[100001] = { 0, };


void dfs(int i){ 
	if (member[i].size() == 0)
		return;

	for (int j = 0; j < member[i].size(); j++) {
		scr[member[i][j]] += scr[i];
		dfs(member[i][j]);
	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;

	scr[1] = 0;
	int x;
	cin >> x;
	for (int i = 2; i <= n; i++) {
		cin >> x;
		member[x].push_back(i);
	}


	for (int j = 0; j < m; j++) {
		int i, w;
		cin >> i >> w;
		scr[i] += w;
	}

	dfs(1);


	//결과 출력
	for (int i = 1; i < n + 1; i++)
		cout << scr[i] << " ";

	return 0;
}