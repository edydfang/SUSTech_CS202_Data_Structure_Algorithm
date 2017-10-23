import java.io.InputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
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

    static class Node {
        public int value;
        public Node next;
        public Node prep;
        public Node head;
        public Node rear;
        public Node current;
        public int size;

        Node(int value) {
            this.value = value;
        }

        Node() {
            this.head = null;
            this.rear = null;

        }
    }

    static int[] arr = new int[300001];
    static int[] change = new int[300001];
    static int n;
    static int m;
    static int k;

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        InputReader sc = new InputReader(inputStream);
        int T = sc.nextInt();
        for (int loop1 = 0; loop1 < T; loop1++) {
            n = sc.nextInt();
            m = sc.nextInt();
            k = sc.nextInt();
            int max = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                if (max < arr[i]) {
                    max = arr[i];
                }
            }
            System.out.println(findMaxLength(binarySearch(max)));                        
        }

    }

    public static int binarySearch(int max) {
        int min = 0;
        int mid = 0;
        while (min <= max) {
            mid = (min + max) / 2;           
            if (findMaxLength(mid) < m) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        return max;
    }
    
    public static int findMaxLength(int mid) {
        Node node = new Node();
        int count = 0;
        int MaxM = 0;
        for (int i = 0; i < n; i++) {
            if (mid > arr[i]) {
                change[i] = 0;
            } else {
                change[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (change[i] == 1) {
                pushLast(node, new Node(change[i]));
            } else {
                if (count < k - 1) {
                    pushLast(node, new Node(change[i]));
                    count++;
                } else {
                    while (node.size > 0 && peek(node) != 0) {
                        popFirst(node);
                    }
                    if (node.size > 0) {
                        popFirst(node);
                        count--;
                    }
                    pushLast(node, new Node(change[i]));
                    count++;
                }
            }

            if (MaxM < node.size) {
                MaxM = node.size;

            }
        }
        return MaxM;
    }

    
    public static void popFirst(Node node) {
        if (node.head.next != null) {
            node.head = node.head.next;
            node.head.prep = null;
        } else {
            node.head = null;
        }
        node.size--;
    }

    public static Node pushLast(Node node, Node newNode) {
        if (node.head == null) {
            node.head = newNode;
            node.rear = newNode;
        } else {
            node.rear.next = newNode;
            newNode.prep = node.rear;
            node.rear = newNode;
        }
        node.size++;
        return node;
    }

    public static int peek(Node node) {
        return node.head.value;
    }

}
