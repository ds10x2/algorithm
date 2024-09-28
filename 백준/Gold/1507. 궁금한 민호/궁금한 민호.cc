/*

최소 이동 시간을 구해둠
원래 도로가 몇 개 있는지 구하기

두 지점의 합인 경우 -> 경유해서 최소 거리란 뜻

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int city_nums; //도시의 수
int dist[21][21]; //도시 간의 최소 거리
int ans;
int result[21][21];

int main() {

    cin >> city_nums;
    for (int row = 1; row <= city_nums; row++)
        for (int col = 1; col <= city_nums; col++)
            cin >> dist[row][col];

    for (int i = 1; i <= city_nums; i++)
        for (int j = 1; j <= city_nums; j++) {
            if (i == j) continue;
            for (int k = 1; k <= city_nums; k++) {
                if (k == i || k == j) continue;
                if (dist[i][j] == (dist[i][k] + dist[k][j])) {
                    result[i][j] = 2501;
                    result[j][i] = 2501;
                }
                else if (dist[i][j] != 2501 && dist[i][j] > (dist[i][k] + dist[k][j])) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }

    for (int row = 1; row <= city_nums; row++) {
        for (int col = row; col <= city_nums; col++) {
            if (result[row][col] < 2501) ans += dist[row][col];
        }
    }


    cout << ans << endl;
    return 0;
}

