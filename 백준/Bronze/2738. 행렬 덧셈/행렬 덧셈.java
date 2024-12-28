import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb;

    private static int n, m;
    private static int[][] arr;
    private static int num;

    public static void main(String[] args) throws IOException {
    
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine().trim());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n+1][m+1];

        for(int rowIdx = 1; rowIdx <= n; rowIdx++){
            st = new StringTokenizer(br.readLine().trim());
            
            for(int colIdx = 1; colIdx <= m; colIdx++){
                num = Integer.parseInt(st.nextToken());
                arr[rowIdx][colIdx] = num;
            }
        }
        for(int rowIdx = 1; rowIdx <= n; rowIdx++){
            st = new StringTokenizer(br.readLine().trim());
            
            for(int colIdx = 1; colIdx <= m; colIdx++){
                num = Integer.parseInt(st.nextToken());
                arr[rowIdx][colIdx] += num;
            }
        }

        for(int rowIdx = 1; rowIdx <= n; rowIdx++){
            for(int colIdx = 1; colIdx<=m; colIdx++)
                sb.append(arr[rowIdx][colIdx]).append(" ");
            sb.append("\n");
        }

        System.out.println(sb);

    }
}