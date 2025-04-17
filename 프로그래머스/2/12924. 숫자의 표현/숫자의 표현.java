class Solution {
    
    public void fillArray(int n, int[] arr){
        arr[0] = 0;
        for(int idx = 1; idx<= n; idx++){
            arr[idx] = idx + arr[idx-1];
        }
    }

    public int getAnswer(int n, int[] arr){
        int result = 0;
        int start = 0;
        int end = 1;
    // arr[end] - arr[start]가 n보다 작으면 end++
    // arr[end] - arr[start]가 n보다 크면 start++
    // arr[end] - arr[start]가 n과 같으면 result++하고 end++ 
    
        while(start <= n && end <= n){
            if(arr[end] - arr[start] > n){
                start++;
            }
            else{
                if(arr[end] - arr[start] == n) result++;
                end++;
            }
        }
    
        return result;
    }
    
    public int solution(int n) {
        int answer = 0;
    
        int[] arr = new int[n + 1];
        fillArray(n, arr);
        answer = getAnswer(n, arr);
    
        return answer;
    }
}