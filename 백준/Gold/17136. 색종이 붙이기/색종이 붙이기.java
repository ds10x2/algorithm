
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/***
 * 
 * 17136 색종이 붙이기
 * 
 * 각 종류의 색종이는 5개씩 가지고 있음
 * 
 */

public class Main {

	public static BufferedReader br;
	public static StringBuilder sb;
	public static StringTokenizer st;

	public static int[][] paper; //초기 종이 정보를 저장할 배열
	//public static boolean[][] visited;
	public static int[] colorPaper;
	public static int paperCnt;

	public static int result;
	
	
	public static void attach(int cnt, int paperCnt) {

		if(paperCnt == 0) {
			result = Math.min(result, cnt);
			return;
		}
		if(cnt >= result) return;
	
		for (int row = 0; row < 10; row++)
			for (int col = 0; col < 10; col++) {
				
				if(paper[row][col] == 0) continue;
				//if(visited[row][col]) continue;
				
				for (int idx = 1; idx <= 5; idx++) {
					// 색종이를 붙일 수 있음
					if (!promising(row, col, idx)) continue;

					
					for (int rowIdx = 0; rowIdx < idx; rowIdx++) {
						for (int colIdx = 0; colIdx < idx; colIdx++) {
							paper[row + rowIdx][col + colIdx] = 0;
						}
					}
					
					colorPaper[idx]++;
					attach(cnt + 1, paperCnt - (idx*idx));
					colorPaper[idx]--;
					
					for (int rowIdx = 0; rowIdx < idx; rowIdx++) {
						for (int colIdx = 0; colIdx < idx; colIdx++) {
							paper[row + rowIdx][col + colIdx] = 1;
						}
					}
				}
				return;
			}
		return;
	}

	public static boolean promising(int row, int col, int colored) {
		if (colorPaper[colored] == 5)
			return false; // 이미 특정 사이즈의 색종이를 모두 사용한 경우
		if (paper[row][col] == 0)
			return false; // 색종이를 덮을 수 없는 지점
//		if (visited[row][col])
//			return false; // 이미 방문한 지점

		// 특정 크기의 색종이를 덮을 수 있는지 확인
		for (int rowIdx = 0; rowIdx < colored; rowIdx++) {
			for (int colIdx = 0; colIdx < colored; colIdx++) {
				// 색종이를 붙일 수 없는 영역일 경우 false리턴
				if (row + rowIdx >= 10 || col + colIdx >= 10)
					return false;
				if (paper[row + rowIdx][col + colIdx] == 0)
					return false;
//				if (visited[row + rowIdx][col + colIdx])
//					return false; // 이미 색종이를 붙인 영역이면 false 리턴
			}
		}

		return true;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();

		result = Integer.MAX_VALUE;
		colorPaper = new int[6]; // 사용한 색종이 개수 체크용 배열

		paper = new int[10][10];
		for (int rowIdx = 0; rowIdx < 10; rowIdx++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int colIdx = 0; colIdx < 10; colIdx++) {
				paper[rowIdx][colIdx] = Integer.parseInt(st.nextToken());
				
				if(paper[rowIdx][colIdx] == 1) paperCnt++;
			}
		}

		//visited = new boolean[10][10];

		attach(0, paperCnt);
		System.out.println(result != Integer.MAX_VALUE ? result : -1);
		
		System.out.println(sb);

	}

}