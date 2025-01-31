import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb;

    private static char[] str;
    private static char[] keyword;

    private static int cnt;

    public static void main(String[] args) throws IOException {
    
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        cnt = Integer.parseInt(br.readLine().trim());

        keyword = br.readLine().trim().toCharArray();
        for(int word = 1; word < cnt; word++){
            str = br.readLine().trim().toCharArray();

            for(int idx = 0; idx < keyword.length; idx++){
                if(keyword[idx] != str[idx])
                    keyword[idx] = '?';
            }
        }


        for(int idx = 0; idx < keyword.length; idx++)
            System.out.print(keyword[idx]);

    }
}