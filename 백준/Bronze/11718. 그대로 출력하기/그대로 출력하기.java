import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb;

    public static void main(String[] args) throws IOException {
            br = new BufferedReader(new InputStreamReader(System.in));
        
            sb = new StringBuilder();
        
            String str = br.readLine();
            while(str != null){
                sb.append(str.trim()).append("\n");
                
                str = br.readLine();
            }
        
            System.out.println(sb);
            
        
    }
}
