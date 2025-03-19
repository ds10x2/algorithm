#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> dp(triangle.size(), vector<int>());
    
    for(int idx = 0; idx < triangle.size(); idx++){
        dp[triangle.size()-1].push_back(triangle[triangle.size()-1][idx]);
    }
    
    for(int row_idx = triangle.size() - 2; row_idx >= 0; row_idx--){
        for(int idx = 0; idx <= row_idx; idx++){
            dp[row_idx].push_back(triangle[row_idx][idx] + max(dp[row_idx + 1][idx], dp[row_idx + 1][idx + 1]));
        }
    }
    
    
    return dp[0][0];
}