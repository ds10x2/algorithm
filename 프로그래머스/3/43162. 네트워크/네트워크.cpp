#include <string>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start_point, vector<bool> &visited, vector<vector<int>> &computers){
    visited[start_point] = true;
    queue<int> q;
    
    q.push(start_point);
    
    while(!q.empty()){
        int point = q.front();
        q.pop();
        
        for(int idx = 0; idx < computers[point].size(); idx++){
            if(visited[idx]) continue; //이미 방문한 경우
            if(computers[point][idx] == 0) continue; //연결이 안 되어 있는 경우
            q.push(idx);
            visited[idx] = true;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(computers.size(), false);
    for(int idx = 0; idx < computers.size(); idx++){
        if(visited[idx]) continue;
        BFS(idx, visited, computers);
        answer++;
    }
    
    return answer;
}