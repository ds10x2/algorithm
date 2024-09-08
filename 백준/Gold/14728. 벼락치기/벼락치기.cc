/*

1. 여러 단원을 융합한 문제는 출제하지 않음
2. 한 단원에 한 문제를 출제. 단, 그 단원에 모든 내용을 알고 있어야 풀 수 있는 문제를 낼 것.

<입력>
단원 개수, 총 공부 시간
예상 공부 시간, 각 단원 별 배점


*/

#include <iostream>
using namespace std;

int cnt, total_time;
int s, t;
int arr[10001];

int main() {

	cin >> cnt >> total_time;
	for (int idx = 0; idx < cnt; idx++) {
		cin >> t >> s;
		for (int time = total_time; time >= t; time--)
			arr[time] = max(arr[time], arr[time - t] + s);
	}

	cout << arr[total_time];



	return 0;
}