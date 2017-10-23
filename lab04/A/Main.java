import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            Stack st = new Stack();
            for (int j = 0; j < m; j++) {
                switch (sc.nextInt()) {
                case 1:
                    int x = sc.nextInt();
                    if (st.size()<n) {
                        st.push(x);
                    } else {
                        System.out.println(x);
                    }
                    break;
                case 2:
                    if (!st.isEmpty()) {
                        System.out.println(st.pop());
    
                    }
                    break;
                }
            }
            while(!st.isEmpty()) {
                System.out.println(st.pop());
            }
        }

    }

}
