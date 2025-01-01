import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    // private static StringTokenizer st;
    private static StringBuilder sb;

    private static char[] str;
    private static char[] keyword;

    public static void main(String[] args) throws IOException {
    
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        str = br.readLine().trim().toCharArray();
        keyword = br.readLine().trim().toCharArray();


        int idx = 0;
        int checkpoint = 0;
        int result = 0;
        while(idx + checkpoint < str.length){
            
            if(str[idx + checkpoint] == keyword[checkpoint]){
                checkpoint++;
            }
            else{
                idx++;
                checkpoint = 0;
            }
            
            if(checkpoint == keyword.length){
                result++;
                idx += checkpoint;
                checkpoint = 0;
            }

            
        }
        

        System.out.println(result);

    }
}