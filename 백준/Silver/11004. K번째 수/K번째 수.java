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

    private static int[] numList;
    private static PriorityQueue<Integer> pq;

    private static int n, k;

    public static void main(String[] args) throws IOException {
            br = new BufferedReader(new InputStreamReader(System.in));

            st = new StringTokenizer(br.readLine().trim());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            pq = new PriorityQueue<>();

            st = new StringTokenizer(br.readLine().trim());
            for(int i = 0; i < n; i++){
                pq.add(Integer.parseInt(st.nextToken()));
            }

            while(k > 1){
                k--;
                pq.poll();
            }

            System.out.println(pq.peek());
    }
}
