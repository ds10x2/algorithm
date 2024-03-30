
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

/***
 * 
 * 다리의 길이는 2 이상
 * 방향이 바뀌어선 안됨
 * 교차가능
 * 
 * 섬은 bfs를 통해 덩어리를 하나씩 만들음
 * map에 숫자로 표시
 * 
 * 섬의 외곽에서 한 방향으로 직진
 * 다른 섬을 만난다면 거리 갱신
 * -> 모든 섬 반복
 * 
 * 만들어진 인접행렬로 섬을 이을 수 있는지 확인
 * 모든 섬 연결이 불가능 하면 -1 출력
 * 
 *
 */


public class Main {
	
	static class Pos{
		int row, col;
		Pos(int row, int col){
			this.row = row;
			this.col = col;
		}
	}
	public static BufferedReader br;
	public static StringBuilder sb;
	public static StringTokenizer st;
	
	public static int rowSize, colSize; 
	public static int[][] map;
	
	public static int[][] dist; //거리 저장
	
	public static Queue<Pos> island;
	public static boolean[] visited;
	public static int[] minEdge;
	public static int cnt, islandCnt;
	
	public static Pos curr;
	public static int nRow, nCol;
	
	public static final int[][] DELTA = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	public static boolean isAvailable(int row, int col) {
		if(row < 0 || row >= rowSize || col < 0 || col >= colSize) return false;
		return true;
	}
	
	public static void makeIsland() {
		island = new ArrayDeque<>();
		
		islandCnt = 1; //섬은 2부터 시작
		
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
			for(int colIdx = 0; colIdx < colSize; colIdx++) {
			
				if(map[rowIdx][colIdx] != 1) continue;
				
				islandCnt++;
				
				island.offer(new Pos(rowIdx, colIdx));
				map[rowIdx][colIdx] = islandCnt;
				
				while(!island.isEmpty()) {
					
					curr = island.poll();
					
					for(int idx = 0; idx < 4; idx++) {
						nRow = curr.row + DELTA[idx][0];
						nCol = curr.col + DELTA[idx][1];
						
						if(!isAvailable(nRow, nCol)) continue;
						if(map[nRow][nCol] != 1) continue;
						
						//섬 표시하기
						island.offer(new Pos(nRow, nCol));
						map[nRow][nCol] = islandCnt;
					}
					
				}
				
			}
		}
	}
	
	public static void makeBridge() {
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
			for(int colIdx = 0; colIdx < colSize; colIdx++) {
				
				if(map[rowIdx][colIdx] == 0) continue;
				
				for(int idx = 0; idx < 4; idx++) {
					
					dfs(rowIdx, colIdx, idx, map[rowIdx][colIdx], 0);
					
				}
				
			}
		}
	}
	
	public static void dfs(int row, int col, int direct, int start, int cnt) {
		
		//도착한 곳이 물이 아니고 시작한 지점도 아닐 경우
		if(map[row][col] != 0 && map[row][col] != start) {
			if(cnt == 2) return;
			dist[start - 2][map[row][col] - 2] = Math.min(cnt - 1, dist[start - 2][map[row][col] - 2]);
			return;
		}
		
		int nextRow = row + DELTA[direct][0];
		int nextCol = col + DELTA[direct][1];
		
		if(!isAvailable(nextRow, nextCol)) return;
		if(map[nextRow][nextCol] == start) return;
		dfs(nextRow, nextCol, direct, start, cnt+1);
	}
	
	public static int result;
	public static void findMin() {
		visited = new boolean[islandCnt];
		minEdge = new int[islandCnt];
		
		Arrays.fill(minEdge, Integer.MAX_VALUE);
		minEdge[0] = 0;
		result = 0;
		int cnt;
		for(cnt = 0; cnt < islandCnt; cnt++) {
			int min = Integer.MAX_VALUE;
			int minIsland = -1;
			
			for(int idx = 0; idx < islandCnt; idx++) {
				if(!visited[idx] && minEdge[idx] < min) {
					min = minEdge[idx];
					minIsland = idx;
				}
			}

			if(minIsland == -1) break;
			result += min;
			visited[minIsland] = true;
			
			
			for(int idx = 0; idx < islandCnt; idx++) {
				if(!visited[idx] && dist[minIsland][idx] < Integer.MAX_VALUE
						&& minEdge[idx] > dist[minIsland][idx]) {
					minEdge[idx] = dist[minIsland][idx];
				}
			}
		}
		
		if(cnt != islandCnt) result = -1;
	}
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine().trim());
		rowSize = Integer.parseInt(st.nextToken());
		colSize = Integer.parseInt(st.nextToken());
		
		map = new int[rowSize][colSize];
		
		//지도 정보 입력 받기
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
			st = new StringTokenizer(br.readLine().trim());
			for(int colIdx = 0; colIdx < colSize; colIdx++) {
				map[rowIdx][colIdx] = Integer.parseInt(st.nextToken());
			}
		}
		
		//지도에 섬 표기하기
		makeIsland();
		
		//최종적인 섬 개수
		islandCnt--;
		
		//거리 저장
		dist = new int[islandCnt][islandCnt];
		
		for(int idx = 0; idx < islandCnt; idx++)
			Arrays.fill(dist[idx], Integer.MAX_VALUE);
		
		makeBridge();
			
		findMin();
		
		System.out.println(result);
	}

}