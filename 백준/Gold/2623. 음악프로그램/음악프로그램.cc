#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

/*

백준 2623 음악프로그램

위상정렬 문제

1. 진입 차수가 0인 노드를 큐에 모두 넣는다
2. 진입차수가 0인 노드를 꺼내어 자신과 인접한 노드의 간선을 제거한다
	인접한 노드의 진입 차수를 1 감소시킨다
3. 간선 제거 후 진입 차수가 0이 된 노드를 큐에 넣는다.
(진입 차수: 자신으로 들어오는 간선의 수)

*/

int singer_cnt, pd_cnt;
int pd_singer;

int singer1, singer2;
vector<int> graph[1001]; //간선 정보 저장
int in_degree[1001];
vector<int> result;
queue<int> q; //위상 정렬용 큐

void topology_sort() {
	for (int idx = 1; idx <= singer_cnt; idx++)
		if (in_degree[idx] == 0) q.push(idx);

	for (int idx = 0; idx < singer_cnt; idx++) {

		//n번 끝내기 전에 큐가 비면 사이클이 발생했다는 뜻
		if (q.empty()) {
			return;
		}

		int now = q.front();

		q.pop();

		result.push_back(now);

		for (int n_idx = 0; n_idx < graph[now].size(); n_idx++) {
			int next = graph[now][n_idx];
			if (--in_degree[next] == 0) q.push(next);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> singer_cnt >> pd_cnt;

	for (int idx = 0; idx < pd_cnt; idx++) {
		cin >> pd_singer;
		cin >> singer1;
		for (int s = 1; s < pd_singer; s++) {
			cin >> singer2;

			graph[singer1].push_back(singer2); 

			in_degree[singer2]++;

			singer1 = singer2;
		}
	}

	topology_sort();

	if (result.size() == singer_cnt) {
		for (int idx = 0; idx < singer_cnt; idx++)
			cout << result[idx] << "\n";
	}
	else
		cout << 0 << "\n";

	
	return 0;
}