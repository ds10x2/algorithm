import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
            br = new BufferedReader(new InputStreamReader(System.in));
        
            
            st = new StringTokenizer(br.readLine().trim());
            int result = 0;
            while(st.hasMoreTokens()){
                st.nextToken();
                result++;
            }
            
        
            System.out.println(result);
            
        
    }
}
