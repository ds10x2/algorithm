/*

*/



#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n; //센서의 개수
int k; //집중국의 개수
vector<int> sensors;
vector<int> dis;

int main() {

    cin >> n >> k;

    int sensor;
    for (int idx = 0; idx < n; idx++) {
        cin >> sensor;
        sensors.push_back(sensor);
    }

    sort(sensors.begin(), sensors.end());

    for (int idx = 1; idx < n; idx++) {
        dis.push_back(sensors[idx] - sensors[idx - 1]);
    }

    sort(dis.begin(), dis.end());

    int result = 0;
    for (int idx = 0; idx < n - k; idx++) {
        result += dis[idx];
    }
    cout << result;

    return 0;
}

