/*

백준 9084번 동전

동전의 종류가 주어질 때 주어진 금액을 만드는 모든 방법을 세는 프로그램 작성

테스트케이스 수
금액(1~10000원)
만들어야할 금액

DP를 이용


*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int test_case;
int target;
int coins_cnt;
int coins[21];
int result[10001];


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	//각 테스트케이스 반복
	cin >> test_case;
	for (int tc = 0; tc < test_case; tc++) {

		for (int idx = 0; idx < 10000; idx++) {
			result[idx] = 0;
		}
		
		//동전의 금액을 입력 받음(오름차순)
		cin >> coins_cnt;
		for (int idx = 0; idx < coins_cnt; idx++) {
			cin >> coins[idx];
		}

		result[0] = 1;

		//만들 금액
		cin >> target;

		for (int idx = 0; idx < coins_cnt; idx++) {
			for (int c = coins[idx]; c <= target; c++) {
				result[c] += result[c - coins[idx]];
			}
		}

		cout << result[target] << endl;

	}


	return 0;
}