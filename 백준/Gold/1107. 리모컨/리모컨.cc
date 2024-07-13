/*

백준 1107번
버튼: 0~9, +, -

고장난 버튼이 주어졌을 때 N번 채널로 이동하기 위해서 최소 몇번의 버튼을 눌러야할지

현재 채널: 100

<입력>
이동하려는 채널
고장난 버튼의 개수
고장난 버튼


1. 100에서 + -로만 수를 만든다.
2. 고장나지 않은 버튼들로 수를 조합하고 + -로 조정한다.


*/


#include <iostream>
#include <cmath>
using namespace std;

int channel; //이동하려는 채널
bool buttons[10]; //0~9까지의 버튼
int now = 100; //시작하는 채널
int result;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	//이동하려는 채널을 입력 받음
	cin >> channel;

	int btns; 
	cin >> btns;
	for (int idx = 0; idx < btns; idx++) {
		int x;
		cin >> x;
		buttons[x] = true; //고장난 버튼 표시
	}


	result = abs(100 - channel);

	//0일 때
	if (!buttons[0]) {
		result = min(result, channel + 1);
	}

	//전부 확인
	for (int num = 1; num <= 999999; num++) {

		int tmp = num;
		bool check = true;
		int num_len = 0;

		while (tmp > 0) {
			if (buttons[tmp % 10]) {
				check = false;
			}
			tmp /= 10;
			num_len++;
		}

		if (check) {
			result = min(result, abs(channel - num) + num_len);
		}

	}

	cout << result << endl;

	return 0;
}