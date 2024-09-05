#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N; //도시의 수
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
long long dis[100001];


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	dis[1] = 0;

	cin >> N;
	for (int i = 2; i < N+1; i++) {
		int d;
		cin >> d;
		dis[i] = dis[i - 1] + d;
	}
	for (int i = 1; i <= N; i++) {
		int price;
		cin >> price;
		q.push({ price, i });
	}

	long long price = q.top().first;
	int pos = q.top().second;
	long long sum = (price * (dis[N] - dis[pos]));
	q.pop();

	while (pos > 1) {

		int tprice = q.top().first;
		int tpos = q.top().second;
		q.pop();

		if (tpos > pos) continue;
		sum += (tprice * (dis[pos] - dis[tpos]));

		pos = tpos;
		price = tprice;

	}

	cout << sum;

	return 0;
}