#include <iostream>
using namespace std;

/*

백준 10942번 팰린드롬?
팰린드롬: 앞으로 읽나 뒤로 읽나 같은 것

자연수 N개를 칠판에 적음
S번째 수부터 E번째까지 수가 팰린드롬인지 아닌지

s부터 e까지가 팰린드롬이려면 s+1, e-1도 팰린드롬

*/

int N, M ;
int s, e;
int arr[2001];
bool isPalindrome[2001][2001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	//수열 정보 입력
	for (int idx = 1; idx <= N; idx++)
		cin >> arr[idx];

	for (int idx = 1; idx <= N; idx++)
		isPalindrome[idx][idx] = true;
	
	for (int idx = 1; idx <= N - 1; idx++)
		if (arr[idx] == arr[idx + 1])
			isPalindrome[idx][idx + 1] = true;
	

	for (int i = N - 2; i > 0; i--)
		for (int j = i + 2; j <= N; j++)
			if (arr[i] == arr[j] && isPalindrome[i + 1][j - 1]) {
				isPalindrome[i][j] = true;
			}
	

	cin >> M;

	//질문 입력
	for (int idx = 0; idx < M; idx++) {
		cin >> s >> e;

		if (isPalindrome[s ][e]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}



	return 0;
}