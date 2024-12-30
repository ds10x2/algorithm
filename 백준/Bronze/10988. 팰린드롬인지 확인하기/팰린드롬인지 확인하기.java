import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb;

    public static void main(String[] args) throws IOException {
    
        br = new BufferedReader(new InputStreamReader(System.in));
        // sb = new StringBuilder();

        String str = br.readLine().trim();
        int flag = 1;

        for(int idx = 0; idx < str.length()/2; idx++){
            if(str.charAt(idx) != str.charAt(str.length() - idx - 1)){
                flag = 0;
                break;
            }
        }


        System.out.println(flag);

    }
}