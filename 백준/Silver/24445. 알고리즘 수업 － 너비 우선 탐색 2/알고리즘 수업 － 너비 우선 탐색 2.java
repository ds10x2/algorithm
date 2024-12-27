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

    private static int n, m, r;
    // private static boolean[][] graph;
    private static ArrayList[] graph;

    private static Queue<Integer> q;
    private static int[] visited;

    public static void BFS(){
        q = new ArrayDeque<Integer>();
        visited = new int[n + 1];

        int visitedCnt = 1;
        q.offer(r);
        visited[r] = visitedCnt;

        visitedCnt++;

        while(!q.isEmpty()){
            int v = q.poll();

            for(int idx = 0; idx < graph[v].size(); idx++){
                if(visited[(int) graph[v].get(idx)] > 0) continue;

                q.offer((int) graph[v].get(idx));
                visited[(int) graph[v].get(idx)] = visitedCnt;
                visitedCnt++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
    
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine().trim());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        // graph = new boolean[n + 1][n + 1];
        graph = new ArrayList[n+1];
        for(int idx = 0; idx <= n; idx++)
            graph[idx] = new ArrayList<>();

        for(int idx = 0; idx < m; idx++){
            st = new StringTokenizer(br.readLine().trim());
            int u, v;
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            graph[u].add(v);
            graph[v].add(u);
        }

        for(int idx = 1; idx <= n; idx++)
            graph[idx].sort(Comparator.reverseOrder());

        BFS();

        for(int idx = 1; idx <= n; idx++)
            sb.append(visited[idx]).append(("\n"));
        
        System.out.println(sb);

    }
}