#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

/*

9466

DFS로 st, ed가 같은 학생 찾기..?

*/

int test_case;
int student_cnt;
int students[100001];
bool visited[100001];
bool cycle[100001];

int cnt;

void DFS(int s) {
	visited[s] = true;
	int next = students[s];

	if (!visited[next]) DFS(next);
	else if (!cycle[next]) {
		for (int idx = next; idx != s; idx = students[idx])
			cnt++;
		cnt++;
	}
	cycle[s] = true;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test_case;
	for (int tc = 0; tc < test_case; tc++) {
		cin >> student_cnt;
		for (int idx = 1; idx <= student_cnt; idx++)
			cin >> students[idx];

		for (int idx = 1; idx <= student_cnt; idx++)
			if (!visited[idx])
				DFS(idx);
		cout << student_cnt - cnt << "\n";
		cnt = 0;

		memset(visited, false, sizeof(visited));
		memset(cycle, false, sizeof(cycle));
	}
	
	return 0;
}