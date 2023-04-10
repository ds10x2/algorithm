#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

int n; //º°ÀÇ ¼ö
vector <pair<double, double>> star;
//double arr[101][101];
vector<pair<double, int>> star_dist[101];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
bool visited[101] = { false, };
double sum;

void find_dist() {

//	for (int i = 0; i < n; i++) {
//		arr[i][i] = 0;
//	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double x = fabs(pow(star[i].first - star[j].first, 2));
			double y = fabs(pow(star[i].second - star[j].second, 2));
			double result = sqrt(x + y);
			//arr[i][j] = result;
			//arr[j][i] = result;

			star_dist[i].push_back({ result, j });
			star_dist[j].push_back({ result, i });
		}
	}
}

void found() {
	sum = 0;
	q.push({ 0,0 });

	while (!q.empty()) {

		double dist = q.top().first;
		int node = q.top().second;

		q.pop();

		if (visited[node])
			continue;
		visited[node] = true;
		sum += dist;

		for (int i = 0; i < star_dist[node].size(); i++) {
			if (!visited[star_dist[node][i].second])
				q.push(star_dist[node][i]);
		}

		
	}

}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;

		star.push_back({ x, y });
	}

	find_dist();

	cout << fixed;
	cout.precision(2);

	found();

	cout << sum;

	return 0;
}