/*

N개의 도시
한 도시에서 출발해서 다른 도시에 도착하는 M개의 버스
A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용 최소화

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int city_num; // 도시의 수
int bus_num; // 버스의 수
vector<pair<int, int>> dist[1001];
int st, ed;



vector<int>  dijkstra() {

    priority_queue<pair<int, int>> pq;
    vector<int> result(city_num + 1, 100000001);

    result[st] = 0;
    pq.push({ 0, st });


    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;

        pq.pop();

        if (cur_dist > result[cur_node]) continue;

        for (int idx = 0; idx < dist[cur_node].size(); idx++) {
            int next_node = dist[cur_node][idx].first; //인접 정점 번호
            int next_dist = cur_dist + dist[cur_node][idx].second;

            if (next_dist < result[next_node]) {
               
                result[next_node] = next_dist;
                pq.push({ -next_dist, next_node });
            }
        }
    }

    return result;

}

int main() {

    cin >> city_num >> bus_num;

    int d;
    for (int idx = 0; idx < bus_num; idx++) {
        cin >> st >> ed >> d;
        dist[st].push_back({ ed, d });
    }


    //최소비용을 구해야하는 출발점의 도시번호와 도착지의 도시번호
    cin >> st >> ed;

    vector<int> result = dijkstra();

    cout << result[ed] << endl;


    return 0;
}

