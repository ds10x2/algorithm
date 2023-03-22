#include <iostream>
#include <algorithm>
using namespace std;

int N;
int cost[1001][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int R, G, B;
		cin >> R >> G >> B;
		if (i == 0) {
			cost[i][0] = R;
			cost[i][1] = G;
			cost[i][2] = B;
		}
		else {
			if (cost[i - 1][1] + R < cost[i - 1][2] + R)
				cost[i][0] = cost[i - 1][1] + R;
			else
				cost[i][0] = cost[i - 1][2] + R;

			if (cost[i - 1][0] + G < cost[i - 1][2] + G)
				cost[i][1] = cost[i - 1][0] + G;
			else
				cost[i][1] = cost[i - 1][2] + G;
			
			if (cost[i - 1][0] + B < cost[i - 1][1] + B)
				cost[i][2] = cost[i - 1][0] + B;
			else
				cost[i][2] = cost[i - 1][1] + B;
		}
	}

	int Min = min(cost[N - 1][0], min(cost[N - 1][1], cost[N - 1][2]));

	cout << Min;


	return 0;
}