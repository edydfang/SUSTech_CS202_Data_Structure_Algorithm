import java.io.InputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Main {
 
    static class Node {
        public int value;
        public int index;
        public Node next;
        public Node head;
        public Node current;
 
        Node(int index, int value) {
            this.index = index;
            this.value = value;
 
        }
 
        Node() {
            this.head = null;
        }
    }
     
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
         
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
         
        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
 
    public static void main(String[] args) {            
        InputStream inputStream = System.in;
        InputReader sc = new InputReader(inputStream);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();
            int[] ans = new int[n];
            Node st = new Node();
 
            for (int j = 1; j <= n; j++) {
                int num = sc.nextInt();
                Node node = new Node(j, num);
                if (isEmpty(st)) {
                    push(st, node);
                } else {
                    if (num > peek(st).value) {
                        while (!isEmpty(st)) {
                            if (num > peek(st).value) {
                                ans[peek(st).index - 1] = j;
                                pop(st);
                            } else {
                                break;
                            }
                        }
                    }
                    push(st, node);
                }
            }
            StringBuffer Ans = new StringBuffer();
            for (int a : ans) {
                Ans.append(a);
                Ans.append("\n");
            }
            System.out.print(Ans);
 
        }
 
    }
 
    public static Node push(Node node, Node newNode) {
        if (node.head == null) {
            node.head = newNode;
        } else {
            newNode.next = node.head;
            node.head = newNode;
 
        }
        return node;
    }
 
    public static void pop(Node node) {
        if (node.head.next != null) {
            node.head = node.head.next;
        } else {
            node.head = null;
        }
    }
 
    public static boolean isEmpty(Node node) {
        if (node.head == null) {
            return true;
        } else {
            return false;
        }
    }
 
    public static Node peek(Node node) {
        return node.head;
    }
 
    public static void display(Node node) {
        node.current = node.head;
        StringBuffer ans = new StringBuffer();
        while (node.current != null) {
            ans.append(node.current.value);
            ans.append("\n");
            node.current = node.current.next;
        }
        System.out.print(ans);
    }
 
    public static void displayNode(Node node) {
        System.out.println(node.value);
    }
 
}