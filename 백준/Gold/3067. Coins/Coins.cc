#include <iostream>
#include <cstring>
using namespace std;

/*
	3067 Coins
	동전의 종류가 주어질 때 주어진 금액을 만든느 모든 방법을 세는 프로그램

	<입력>
	테스트 케이스 수 
	동전의 가지 수
	동전의 각 금액(오름차순 정렬, 1 <= <= 10000)
	만들어야하는 금액 (1 <= <= 10000)
*/
long long arr[10001];

int test_case;
int coin_cnt, target;
int coin;
int coins[21];

int main() {

	//테스트케이스
	cin >> test_case;
	//테스트 케이스 반복
	for (int tc = 1; tc <= test_case; tc++) {

		//배열 초기화
		memset(arr, 0, sizeof(arr));

		//코인 종류 입력 받기
		cin >> coin_cnt;
		for (int idx = 0; idx < coin_cnt; idx++) {
			cin >> coin;
			coins[idx] = coin;
		}

		cin >> target;

		arr[0] = 1;

		for (int coin_idx = 0; coin_idx < coin_cnt; coin_idx++) {
			for (int idx = 1; idx <= target; idx++) {
				if (idx - coins[coin_idx] >= 0)
					arr[idx] += arr[idx - coins[coin_idx]];
			}
		}


		cout << arr[target] << endl;
	}


	return 0;
}