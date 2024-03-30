import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/***
 * 
 * 
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
	
	static class Hedgehog{
		Pos pos;
		int cnt;
		Hedgehog(Pos pos, int cnt){
			this.pos = pos;
			this.cnt = cnt;
		}
	}

	public static BufferedReader br;
	public static StringBuilder sb;
	public static StringTokenizer st;
	
	public static int rowSize;
	public static int colSize; //지도 사이즈
	public static char[][] map; //지도
	public static int result;
	
	public static Pos start;
	public static Pos end;
	
	public static final int[][] DELTA = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	public static Queue<Pos> water;

	public static Queue<Hedgehog> move;
	public static boolean[][] visited; //방문 배열
	
	public static int waterCnt;
	public static Pos now;
	public static int nextRow, nextCol;
	public static Hedgehog curr;
	public static int checkCnt;
	
	public static boolean isAvailable (int row, int col) {
		if(row < 0 || row >= rowSize|| col < 0 || col >= colSize) return false;
		return true;
	}
	
	public static void watering() {
		waterCnt = water.size();
		
		while(waterCnt > 0) {
			now = water.poll();
			waterCnt--;
			
			for(int idx = 0; idx < 4; idx++) {
				nextRow = now.row + DELTA[idx][0];
				nextCol = now.col + DELTA[idx][1];
				
				if(!isAvailable(nextRow, nextCol)) continue;
				if(map[nextRow][nextCol] == 'X' || map[nextRow][nextCol] == 'D'
						|| map[nextRow][nextCol] == '*') continue;
				
				map[nextRow][nextCol] = '*';
				water.offer(new Pos(nextRow, nextCol));
			}
		}
	}
	
	public static void search() {
		move = new ArrayDeque<>();
		visited = new boolean[rowSize][colSize];
		
		//시작지점
		move.offer(new Hedgehog(start, 0));
		visited[start.row][start.col] = true;
		checkCnt = -1;
		
		//고슴도치는 물이 차오를 예정인 곳으로 이동이 불가능함
		// -> 물이 먼저 차오르게 함
		
		while(!move.isEmpty()) {
			
			curr = move.poll();
			
			if(curr.cnt > checkCnt) {
				watering();
				checkCnt++;
			}
			
			
			//System.out.println(curr.pos.row + " " + curr.pos.col);
			for(int idx = 0; idx < 4; idx++) {
				nextRow = curr.pos.row + DELTA[idx][0];
				nextCol = curr.pos.col + DELTA[idx][1];
				
				
				if(!isAvailable(nextRow, nextCol)) continue;
				if(visited[nextRow][nextCol]) continue;
				if(map[nextRow][nextCol] == '*') continue; //물
				if(map[nextRow][nextCol] == 'X') continue; //돌
				
				//비버의 굴 도착
				if(map[nextRow][nextCol] == 'D') {
					result = curr.cnt + 1;
					return;
				}
				
				
				visited[nextRow][nextCol] = true;
				move.offer(new Hedgehog(new Pos(nextRow, nextCol), curr.cnt + 1));
			}
		}
	}
	
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		result = Integer.MAX_VALUE;
		
		//지도 사이즈를 입력 받음
		st = new StringTokenizer(br.readLine().trim());
		rowSize = Integer.parseInt(st.nextToken());
		colSize = Integer.parseInt(st.nextToken());
		
		map = new char[rowSize][];
		water = new ArrayDeque<>();
		
		//지도 정보 저장
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
			//지도 정보를 한줄 씩 입력 받음
			map[rowIdx] = br.readLine().trim().toCharArray();
			
			for(int colIdx = 0; colIdx < colSize; colIdx++) {
				
				//고슴도치 위치
				if(map[rowIdx][colIdx] == 'S')
					start = new Pos(rowIdx, colIdx);
				//비버의 굴
				else if(map[rowIdx][colIdx] == 'D')
					end = new Pos(rowIdx, colIdx);
				//물
				else if(map[rowIdx][colIdx] == '*')
					water.offer(new Pos(rowIdx, colIdx));
				
			}
		}
		
		
		search();
		
		System.out.println(result == Integer.MAX_VALUE ? "KAKTUS" : result);
		
	
	}

}