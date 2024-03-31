import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

/***
 * 
 * 1786 찾기
 * 
 * 문자열 T에 문자열 P가 몇번, 어느 위치에 나타나는지 알아내는 문제
 * 
 * T의 길이: n
 * P의 길이: m
 * n >= m
 * 
 * TMP를 이용
 * 
 * <입력> 1 <= n, m <= 1,000,000 / 알파벳 대소문자, 공백
 * 문자열 T
 * 문자열 P
 * 
 * 
 * 1. 문자열 T와 P를 입력받는다.
 * 2. P의 길이를 크기로 가지는 배열을 만든다.
 * 3. P의 i위치까지의 부분 문자열에 대해 접두사이면서 접미사인 최대 문자열의 길이를 저장한다.
 * 4. 같은 과정으로 P에 대해 T를 검사한다.
 * 
 */

public class Main {

	public static BufferedReader br;
	public static StringBuilder sb;
	public static StringTokenizer st;
	
	public static String original;
	public static String keyword;

	
	public static int[] pattern;
	public static int suffix, prefix;
	public static int idx;
	public static int oriLen, keyLen;
	
	public static ArrayList<Integer> pos;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		original = br.readLine(); //공백포함이므로 trim을 붙여주지 않음
		keyword = br.readLine();

		oriLen = original.length();
		keyLen = keyword.length();
		
		
		pattern = new int[keyLen];
		
		pattern[0] = 0; //길이가 2이상인 것부터 찾음

		prefix = 0; //접두사
		for(int suffix = 1; suffix <keyLen; suffix++) {
			while(prefix > 0 && keyword.charAt(suffix) != keyword.charAt(prefix)) {
					prefix = pattern[prefix - 1];
			}
				
			//같은 경우
			if(keyword.charAt(suffix) == keyword.charAt(prefix)){
				//다음 접두사로 넘어가 검사
				prefix++;
				pattern[suffix] = prefix;
			}

		}
		
		
		//oiriginal의 길이만큼 검색
		pos = new ArrayList<>();
		int keyIdx = 0;
		for(int len = 0; len < oriLen; len++) {
			
			while(keyIdx > 0 && original.charAt(len) != keyword.charAt(keyIdx)){
				keyIdx = pattern[keyIdx - 1];
			}
			
			
			//일치하는 경우
			if(original.charAt(len) == keyword.charAt(keyIdx)) {
				//System.out.println(original.charAt(len) + " " + len + " " + keyword.charAt(keyIdx) + " " + keyIdx);
				//keyword와 일치하는 부분을 찾음
				if(keyIdx == keyLen - 1) {
					pos.add(len - keyLen + 2);
					keyIdx = pattern[keyIdx];
				}
				//다음 문자로 넘어감
				else {
					//System.out.println(1);
					keyIdx++;
				}
			}

			
		}
		
		sb.append(pos.size()).append("\n");
		for(int p: pos) sb.append(p).append(" ");
		
		System.out.println(sb);
		
	}

}
