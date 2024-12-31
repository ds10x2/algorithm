import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb;

    private static int num;
    private static boolean[] visited;
    private static int[] nums;

    private static void solution(int idx){
        if(idx == num) {
            for(int i = 0; i < num; i++)
                sb.append(nums[i]).append(" ");
            sb.append("\n");
            return;
        }

        for(int i = 1; i <= num; i++){
            if(visited[i]) continue;

            nums[idx] = i;
            visited[i] = true;
            solution(idx+1);
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
    
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        num = Integer.parseInt(br.readLine().trim());
        visited = new boolean[num+1];
        nums = new int[num];
        solution(0);

        System.out.println(sb);

    }
}