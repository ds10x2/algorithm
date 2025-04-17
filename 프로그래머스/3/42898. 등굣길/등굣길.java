/**

오른쪽과 아래쪽으로만 움직임
-> arr[row-1][col] + arr[row][col-1] 합

집의 좌표는 (1,1)
학교의 좌표는 (m, n) -> row가 m, col이 n임을 주의

**/

class Solution {
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        
        long[][] dp = new long[m+1][n+1];
        
        dp[1][1] = 1;

        for(int idx = 0; idx < puddles.length; idx++){
            dp[puddles[idx][0]][puddles[idx][1]] = -1;
        }
        
        for(int rowIdx = 1; rowIdx <=m; rowIdx++){
            for(int colIdx = 1; colIdx <= n; colIdx++){
                
                if(rowIdx == 1 && colIdx == 1) continue; //집
                
                
                if(dp[rowIdx][colIdx] == -1) continue; //물 웅덩이
                
                if(dp[rowIdx-1][colIdx] != -1) dp[rowIdx][colIdx] += dp[rowIdx-1][colIdx];
                if(dp[rowIdx][colIdx-1] != -1) dp[rowIdx][colIdx] += dp[rowIdx][colIdx-1];
                dp[rowIdx][colIdx] %= 1000000007;
                
            }
        }
        answer = (int) dp[m][n];
        return answer;
    }
}