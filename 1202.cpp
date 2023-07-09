#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int bag[300001];
pair<int, int> jewel[300001];
priority_queue<int> pq;
long long sum = 0;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}

	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}

	sort(jewel, jewel + N);
	sort(bag, bag + K);

	int idx = 0;

	for (int i = 0; i < K; i++) {
		while (idx < N && jewel[idx].first <= bag[i])
			pq.push(jewel[idx++].second);

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}