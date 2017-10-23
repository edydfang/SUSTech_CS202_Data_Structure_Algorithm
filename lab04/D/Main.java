import java.util.Scanner;

public class Main {

    static class Node {
        public int value;
        public Node next;
        public Node prep;
        public Node head;
        public Node rear;
        public Node current;

        Node(int value) {
            this.value = value;

        }

        Node() {
            this.head = null;
            this.rear = null;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();
            Node al = new Node();
            for (int j = 0; j < n; j++) {
                switch (sc.nextInt() + "" + sc.nextInt()) {
                case "11":
                    addFirst(al, sc.nextInt());
                    break;
                case "12":
                    pushFirst(al);
                    break;
                case "21":
                    addLast(al, sc.nextInt());
                    break;
                case "22":
                    pushLast(al);
                    break;
                }
            }
            display(al);

        }

    }

    public static Node addFirst(Node node, int num) {
        Node newNode = new Node(num);
        if (node.head == null) {
            node.head = newNode;
            node.rear = newNode;
        } else {
            newNode.next = node.head;
            node.head.prep = newNode;
            node.head = newNode;
        }
        return node;
    }

    public static Node addLast(Node node, int num) {
        Node newNode = new Node(num);
        if (node.head == null) {
            node.head = newNode;
            node.rear = newNode;
        } else {
            node.rear.next = newNode;
            newNode.prep = node.rear;
            node.rear = newNode;
        }
        return node;
    }

    public static void pushFirst(Node node) {
        if (node.head.next != null) {
            node.head = node.head.next;
            node.head.prep = null;
        } else {
            node.head = null;
        }

    }

    public static void pushLast(Node node) {
        if (node.rear.prep != null) {
            node.rear = node.rear.prep;
            node.rear.next = null;
        } else {
            node.head = null;
        }
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
}
