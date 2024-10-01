#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

/*

백준 1647 도시 분할 계획
최소 신장 트리 문제

N개의 집과 M개의 길이 있음
N개의 집을 두 마을로 나눔 -> 각 마을 안에서는 집들이 서로 방문할 경로가 있어야 함
분리된 두 마을 사이에 있는 길들은 필요가 없으므로 없앰
각 마을 내에서도 필요 없는 길은 없앨 수 있음

최소 유지비를 출력


1. 최소스패닝 트리를 구함
2. 최소스패닝 트리 중 가중치가 가장 높은 간선을 없앰

*/

int N, M; //집의 개수, 길의 개수
vector<pair<int, int>> route[100001];
int st, ed, w;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int min_edge[100001];
bool visited[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int idx = 0; idx < M; idx++) {
		cin >> st >> ed >> w;
		route[st].push_back({ w, ed });
		route[ed].push_back({ w, st });
	}

	for (int idx = 1; idx <= N; idx++)
		min_edge[idx] = 100000001;

	min_edge[1] = 0;
	int max_edge = 0;
	pq.push({ 0, 1 });

	int result = 0;
	int node_cnt = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int weight = pq.top().first;

		pq.pop();

		if (visited[now]) continue; //이미 포함된 상태

		max_edge = max(max_edge, weight);
		result += weight; //간선 비용 누적
		visited[now] = true; //트리 정점에 포함 시킴

		node_cnt++;
		if (node_cnt == N) break; //트리 정점에 포함된 개수를 카운팅


		//최적 업데이트
		for (int idx = 0; idx < route[now].size(); idx++) {
			if (!visited[route[now][idx].second] && min_edge[route[now][idx].second] > route[now][idx].first) {
				min_edge[route[now][idx].second] = route[now][idx].first;
				pq.push({ min_edge[route[now][idx].second], route[now][idx].second });
			}
		}
	}

	cout << result - max_edge << "\n";

	return 0;
}