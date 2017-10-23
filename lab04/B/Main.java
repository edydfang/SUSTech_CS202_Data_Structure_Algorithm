import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            Queue<Integer> st = new LinkedList<Integer>();
            for (int j = 0; j < m; j++) {
                switch (sc.nextInt()) {
                case 1:
                    int x = sc.nextInt();
                    if (st.size()<n) {
                        st.add(x);
                    } else {
                        System.out.println(x);
                    }
                    break;
                case 2:
                    if (!st.isEmpty()) {
                        System.out.println(st.remove());
    
                    }
                    break;
                }
            }
            while(!st.isEmpty()) {
                System.out.println(st.remove());
            }
        }

    }

}
