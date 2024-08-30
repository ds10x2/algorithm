import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Student implements Comparable<Student>{
        String name;
        int kor, eng, math;

        Student(String name, int kor, int eng, int math){
            this.name = name;
            this.kor = kor;
            this.eng = eng;
            this.math = math;
        }

        //s보다 앞이면 -1, 동일하면 0, 뒤면 1 리턴
        @Override
        public int compareTo(Student s){
            //이름 사전 순

            //국어 점수 내림차순
            if(this.kor > s.kor) return -1;
            else if(this.kor < s.kor) return 1;

            //국어점수가 같은 경우, 영어 점수 오름차순
            if(this.eng < s.eng) return -1;
            else if(this.eng > s.eng) return 1;

            //국어 영어가 같은 경우, 수학 점수 내림차순
            if(this.math > s.math) return -1;
            else if(this.math < s.math) return 1;

            return this.name.compareTo(s.name);

        }
    }

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb;

    private static int cnt;
    private static Student[] students;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        cnt = Integer.parseInt(br.readLine());
        students = new Student[cnt];

        for(int idx = 0; idx < cnt; idx++) {
            st = new StringTokenizer(br.readLine().trim());

            Student stu = new Student(st.nextToken(),
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()));

            students[idx] = stu;
        }

        Arrays.sort(students);

        sb = new StringBuilder();
        for(int idx = 0; idx < cnt; idx++){
            sb.append(students[idx].name).append("\n");
        }
        System.out.println(sb);
    }
}
