import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * 백준 1238번 파티
 *
 * N개의 숫자로 구분된 각각의 마을에는 한 명의 학생이 살고 있음
 * 마을 사이에는 총 M개의 단방향 도로들 이 있음
 * i번째 길을 지나는데 Ti의 시간을 소비
 * 각 마을에 살고 있는 학생들이 X번 마을에 모인다고 할 때,
 * 각 학생들이 X번 마을에 오고 가는 최단 시간들을 구하고
 * 그 중 가장 많은 시간을 소비하는 학생 구하기
 *
 * 1 <= 마을의 수 <= 1000
 * 1 <= 단방향 도로의 수 <= 10000
 * 1 <= X <= N
 * 1 <= Ti <= 100
 *
 *
 */

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb;

    private static int cnt, road_cnt, party;
    private static int dist[][];
    private static int start, end, distance;

    private static int result;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine().trim());

        //마을의 수, 단방향 도로의 수, 파티가 열리는 마을의 번호
        cnt = Integer.parseInt(st.nextToken());
        road_cnt = Integer.parseInt(st.nextToken());
        party = Integer.parseInt(st.nextToken());

        dist = new int[cnt + 1][cnt + 1];

        for(int row = 1; row <= cnt; row++)
            for(int col = 1; col <= cnt; col++)
                dist[row][col] = Integer.MAX_VALUE;


        for(int idx = 0; idx < road_cnt; idx++){
            st = new StringTokenizer(br.readLine().trim());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());
            distance = Integer.parseInt(st.nextToken());

            dist[start][end] = distance;
        }

        for(int k = 1; k <= cnt; k++){
            for(int i = 1; i <= cnt; i++){

                if(dist[i][k] == Integer.MAX_VALUE) continue;

                for(int j = 1; j <= cnt; j++){
                    if(dist[k][j] == Integer.MAX_VALUE) continue;

                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        dist[party][party] = 0;
        for(int idx = 1; idx <= cnt; idx++){
            result = Math.max(result, dist[idx][party] + dist[party][idx]);
        }

        System.out.println(result);
    }
}
