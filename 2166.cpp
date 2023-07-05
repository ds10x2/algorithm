#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<pair<double, double>> point;

int N;
float S = 0;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	
	cin >> N;

	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		
		point.push_back({ x,y });
	}

	for (int i = 1; i < N; i++) {
		double s = ((point[0].first * point[i-1].second + point[i-1].first * point[i].second + point[i].first * point[0].second)
			- (point[i-1].first * point[0].second + point[i].first * point[i-1].second + point[0].first * point[i].second)) / 2;


		S += s;
	}
	
	cout.precision(1);
	cout << fixed;
	cout << abs(S);


	return 0;
}