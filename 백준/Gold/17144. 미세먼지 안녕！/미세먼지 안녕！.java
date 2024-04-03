
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/***
 * 
 * 17144 미세먼지 안녕!
 * 
 * 공기청정기는 항상 1열에 설치, 두 행 차지
 * 
 * 1. 방의 사이즈와 시간을 입력 받는다.
 * 2. 방의 사이즈를 크기로 가지는 2차원 배열을 만든다.
 * 3. 2차원 배열에 방의 정보를 입력 받는다.
 * 4. 미세먼지를 확산시킨다.
 * 	   새로운 배열을 만든다.
 * 	   상하좌우를 확인하고 확산시킬 수 있는 칸의 수를 센다.
 * 	   나누기 5를 한 값을 확산시킬 수 있는 칸에 더한다.
 *    남은 미세먼지 양을 원래 위치에 더한다.
 *    모든 미세먼지에 대해서 반복한다.
 * 5. 공기청정기가 작동한다.
 * 	   공기청정기에 도착하는 미세먼지는 정화됨
 *    위쪽 공기청정기: 반시계방향으로 순회
 *    아래쪽 공기청정기: 시계방향으로 순회
 * 6. 남은 미세먼지 양을 구해서 더한다.
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
	public static int afterT;
	public static int[][] room;
	public static int[][] tempRoom;
	public static int totalDust;
	public static int top, bottom;
	
	public static int[][] delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	
	public static void spreadDust() {
		tempRoom = new int[rowSize][colSize];
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
			for(int colIdx = 0; colIdx < colSize; colIdx++) {
				
				if(room[rowIdx][colIdx] == 0 || room[rowIdx][colIdx] == -1) continue;
				
				//미세먼지를 퍼트리고
				//회전하는 구간에 있다면 넘겨서 저장하기
				int cnt = 0; //확산될 수 있는 칸 수 세기
				for(int idx = 0; idx < 4; idx++) {
					int nextRow = rowIdx + delta[idx][0];
					int nextCol = colIdx + delta[idx][1];
					
					if(nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize) continue;
					if(room[nextRow][nextCol] == -1) continue;
					
					cnt++;
					saveTemp(nextRow, nextCol, rowIdx, colIdx, room[rowIdx][colIdx] / 5);
				}
				

				saveTemp(rowIdx, colIdx, rowIdx, colIdx, room[rowIdx][colIdx] - (room[rowIdx][colIdx] / 5 * cnt));
			}
		}
		
		 totalDust -= (tempRoom[top][0] + tempRoom[bottom][0]);
		 tempRoom[top][0] =  -1;
		 tempRoom[bottom][0] = -1;
		 //print();
		 copy();
	}
	
	public static void copy() {
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++)
			for(int colIdx = 0; colIdx < colSize; colIdx++)
				room[rowIdx][colIdx] = tempRoom[rowIdx][colIdx];
	}
	
	public static void saveTemp(int nextRow, int nextCol, int row, int col, int value){
		
		if(stayDust(nextRow, nextCol)) {
			tempRoom[nextRow][nextCol] += value;
		}
		else {
			if(nextRow == 0 || nextRow == rowSize - 1) {
				if(nextCol != 0) { //col-1로 이동
					tempRoom[nextRow][nextCol - 1] += value;
					return;
				}
			}
			else if(nextRow == top || nextRow == bottom) {
				if(nextCol != colSize - 1) { //col+1로 이동
					tempRoom[nextRow][nextCol + 1] += value;
					return;
				}
			}
			
			if(nextCol == 0) {
				if(nextRow < top)
					tempRoom[nextRow+1][nextCol] += value;
				else if(nextRow > bottom) 
					tempRoom[nextRow-1][nextCol] += value;
			}
			else if(nextCol == colSize - 1) {
				if(nextRow <= top) {
					tempRoom[nextRow-1][nextCol] += value;
				}
				else if(nextRow >= bottom) {
					tempRoom[nextRow+1][nextCol] += value;
				}
			}
		}
		
	}
	
	public static boolean stayDust(int row, int col) {
		if(row == 0 || row == rowSize - 1) return false;
		if(row == top || row == bottom) return false;
		if(col == 0 || col == colSize - 1) return false;
		return true;
	}
	
	public static void print() {
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
			for(int colIdx = 0; colIdx < colSize; colIdx++)
				System.out.print(tempRoom[rowIdx][colIdx] + " ");
			System.out.println();
		}
		System.out.println();
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		top = -1;
		bottom = -1;
		
		st = new StringTokenizer(br.readLine().trim());
		rowSize = Integer.parseInt(st.nextToken());
		colSize = Integer.parseInt(st.nextToken());
		afterT = Integer.parseInt(st.nextToken());
		
		room = new int[rowSize][colSize];
		
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
			st = new StringTokenizer(br.readLine().trim());
			for(int colIdx = 0; colIdx < colSize; colIdx++) {
				room[rowIdx][colIdx] = Integer.parseInt(st.nextToken());
			
				if(room[rowIdx][colIdx] > 0) totalDust += room[rowIdx][colIdx];
			}
		}
		
		findAir();

		while(afterT > 0) {
			spreadDust();
			afterT--;
		}
		
		System.out.println(totalDust);
	}
	
	public static void findAir() {
		//공기청정기 위치 찾기
		for(int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
			if(room[rowIdx][0] == -1) {
				if(top == -1) top = rowIdx;
				else {
					bottom = rowIdx;
					break;
				}
			}
		}
	}

}
