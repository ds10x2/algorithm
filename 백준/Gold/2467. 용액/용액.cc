#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

/*

산성 용액: 1,000,000,000까지 양의 정수
알칼리성 용액: -1,000,000,000까지의 음의 정수

같은 양의 두 용액을 혼합한 용액의 특성값 = 두개 더한 값

특성값이 0에 가장 가까운 용액을 만들고자 함


*/


int N; //전체 용액의 수
vector<int> acid;
vector<int> alkali;

int acid_idx, alkali_idx;

int ans1, ans2;

int min_acid_and_alkali = 2147483647;

bool is_min(int a) {
	if (abs(a) < abs(min_acid_and_alkali)) {
		min_acid_and_alkali = a;
		return true;
	}
	return false;
}

int main() {

	cin >> N;
	int liquid;
	for (int idx = 0; idx < N; idx++) {
		cin >> liquid;
		if (liquid > 0)
			acid.push_back(liquid);
		else alkali.push_back(liquid);
	}


	if (acid.size() >= 2) {
		if (is_min(acid[0] + acid[1])) {
			ans1 = acid[0];
			ans2 = acid[1];
		}
	}

	if (alkali.size() >= 2) {
		if (is_min(alkali[alkali.size() - 2] + alkali[alkali.size() - 1])) {
			ans1 = alkali[alkali.size() - 2];
			ans2 = alkali[alkali.size() - 1];
		}
	}

	acid_idx = acid.size() - 1;
	while (acid_idx >= 0 && alkali_idx < alkali.size()) {

		int temp = acid[acid_idx] + alkali[alkali_idx];

		if (is_min(temp)) {
			ans2 = acid[acid_idx];
			ans1 = alkali[alkali_idx];
		}


		if (temp > 0) {
			//산성의 절댓값이 더 큰 경우
			acid_idx--;
		}
		else if (temp < 0) {
			//알칼리의 절댓값이 더 큰 경우
			alkali_idx++;
		}
		else {
			//0인 경우
			ans2 = acid[acid_idx];
			ans1 = alkali[alkali_idx];
			break;
		}

	}

	cout << ans1 << " " << ans2 << endl;


	return 0;
}