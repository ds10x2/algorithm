#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int n, m;
int num;
vector<int> truth;
vector<int> party[51]; // 사람 번호 i가 참여하는 파티를 party[i]에 저장
vector<int> person[51];

bool checked[51];
bool visited[51];


void input() {
	cin >> n >> m;
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		truth.push_back(x);
	}

	for (int i = 1; i <= m; i++) {
		int people;
		cin >> people;
		for (int j = 0; j < people; j++) {
			int x;
			cin >> x;
			person[x].push_back(i); //사람 x가 i번째 파티에 참여
			party[i].push_back(x); //i번째 파티에 사람 x가 참여
		}
	}
}

void solution(){

	queue<int> q;

	for (int i = 0; i < num; i++) {
		
		int x = truth[i];

		if (visited[x]) //검사한 사람이면 건너뜀
			continue;

		q.push(x);

		while (!q.empty()) {
			int truthPerson = q.front();

			q.pop();

			for (int j = 0; j < person[truthPerson].size(); j++) {
				int truthParty = person[truthPerson][j]; //진실을 말해야하는 파티

				if (checked[truthParty]) //검사를 완료한 파티는 건너뜀
					continue;
				
				for (int k = 0; k < party[truthParty].size(); k++) {
					int nextPerson = party[truthParty][k]; //다음으로 검사해야하는 사람

					if (visited[nextPerson])
						continue;

					q.push(nextPerson);
					visited[nextPerson] = true;
				}

				checked[truthParty] = true;

			}
		}

	}

	int ans = m;

	for (int i = 1; i <= m; i++) {
		if (checked[i])
			ans--;
	}

	cout << ans;

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();
	solution();



	return 0;
}