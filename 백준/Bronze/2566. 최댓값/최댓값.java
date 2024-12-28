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

    private static int result;
    private static int x, y;
    private static int num;

    public static void main(String[] args) throws IOException {
    
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        result = 0;
        x = 1;
        y = 1;
        for(int rowIdx = 1; rowIdx <= 9; rowIdx++){
            st = new StringTokenizer(br.readLine().trim());
            
            for(int colIdx = 1; colIdx <= 9; colIdx++){
                num = Integer.parseInt(st.nextToken());
                if(num > result){
                    result = num;
                    x = rowIdx;
                    y = colIdx;
                }
            }
        }

        sb.append(result).append("\n").append(x).append(" ").append(y);


        System.out.println(sb);

    }
}