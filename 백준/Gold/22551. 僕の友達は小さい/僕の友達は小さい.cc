/*

백준 22551 僕の友達は小さい

0명을 넣는 것도 패턴 1개로 -> 모든 친구들의 무게가 한계보다 클 경우
문제 그대로 배낭문제...
무게가 같은 경우가 있음


*/



#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MOD 1000000007

long long rucksack[11111];
int friends_num, max_weight;
int weight[200];
long long sum = 0, result = 0;

int main() {
    cin >> friends_num >> max_weight;

    for (int idx = 0; idx < friends_num; idx++) {
        cin >> weight[idx];
    }

    sort(weight, weight + friends_num);

    for (int idx = 0; idx < friends_num; idx++) {
        if (sum > max_weight)
            break;

        memset(rucksack, 0, sizeof(rucksack));
        rucksack[sum] = 1;

        for (int friend1 = idx + 1; friend1 < friends_num; friend1++) {
            for (int w = max_weight; w >= sum + weight[friend1]; w--) {
                (rucksack[w] += rucksack[w - weight[friend1]]) %= MOD;
            }
        }

        for (int s = sum; s <= max_weight; s++) {
            if (s + weight[idx] > max_weight) {
                (result += rucksack[s]) %= MOD;
            }
        }

        sum += weight[idx];
    }

    if (sum <= max_weight)
        result++;

    cout << result << endl;

    return 0;
}


/*
(번역)

나에게는 많은 친구가 있다. 다들 엄청 작다.
나는 친구들과 곧잘 놀러간다. 친구 몇명을 룩색에 넣어서 함께 놀러간다.
나는 매일 아침, 그날 함께 놀러나갈 친구를 정한다. 비어있는 룩색에 한 명씩 친구를 집어 넣는다.
나는 힘이 센 편이 아니다. 그래서 친구를 한 번에 집어 넣을 때 한계가 있다.
나는 한계 내에서 친구를 집어 넣는다. 어떤 순서로 넣을지는 기분에 따라.
나는 넣을 수 있는 친구가 남아있는 한, 친구를 넣는 것을 멈추지 않는다. 절대 멈추지 않는다.
...그래서 룩색에 들어간 친구들의 조합은 전부 몇 종류일까?

입력
입력의 첫 번째 줄에는 정수 N(1<=N<=200)과 정수 W(1<=W<=10,000)이 공백으로 나뉘어져 입력된다.
정수 N은 친구들의 수를, 정수 W는 동시에 넣을 수 있는 친구들의 최대 무게 합을 의미한다.
합이 W를 넘으면 넣을 수 없다.
이어지는 N행에는 친구들의 무게를 나타내는 정수가 입력된다.
정수 wi(1<=wi<=10,000)는 i번째 친구의 무게를 의미한다.

출력
최종적으로 룩색에 들어가있는 친구들의 조합을 생각한다.
그 조합의 수를 1,000,000,007로 나눈 나머지를 출력한다.
아무도 배낭에 들어가지 않는 것도 한 가지로 센다.

*/