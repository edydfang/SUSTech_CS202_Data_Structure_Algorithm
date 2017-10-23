import java.util.Scanner;
public class Main {

    static Scanner sc = new Scanner(System.in);

    static class Node {
        public int index;
        public Node next;
        public Node prep;
        public Node head;
        public Node rear;
        public Node current;

        Node(int index) {
            this.index = index;
        }

        Node() {
            this.head = null;
            this.rear = null;

        }
    }

    public static void main(String[] args) {
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int arr[] = new int[n];
            for(int j=0;j<n;j++) {
                arr[j] = sc.nextInt();
            }
            printMin(arr,n,k);
            printMax(arr,n,k);

        }

    }
    

    public static void printMax(int arr[],int n, int k) {
        Node node = new Node();
        StringBuffer ans = new StringBuffer();
        int i;
        for (i=0; i < k; i++) {
            while(!isEmpty(node) && arr[i]>=arr[peekLast(node)]) {
                popLast(node);
            }
            pushLast(node,new Node(i));           
        }
        
       
        for(;i<n;i++) {
            ans.append(arr[peek(node)]);
            ans.append(" ");
            
            while(!isEmpty(node) && peek(node)<= i-k)
                popFirst(node);
            
            while((!isEmpty(node)) && arr[i] >= arr[peekLast(node)])
                popLast(node);
            
            pushLast(node,new Node(i));
        }
        ans.append(arr[peek(node)]);
        System.out.println(ans);
        
        
        
    }
    
    
    
    public static void printMin(int arr[],int n, int k) {
        Node node = new Node();
        StringBuffer ans = new StringBuffer();
        int i;
        for (i=0; i < k; i++) {
            while(!isEmpty(node) && arr[i]<=arr[peekLast(node)]) {
                popLast(node);
            }
            pushLast(node,new Node(i));           
        }
        
       
        for(;i<n;i++) {
            ans.append(arr[peek(node)]);
            ans.append(" ");
            
            while(!isEmpty(node) && peek(node)<= i-k)
                popFirst(node);
            
            while((!isEmpty(node)) && arr[i] <= arr[peekLast(node)])
                popLast(node);
            
            pushLast(node,new Node(i));
        }
        ans.append(arr[peek(node)]);
        System.out.println(ans);
        
        
        
    }

    public static boolean isEmpty(Node node) {
        if (node.head == null) {
            return true;
        } else {
            return false;
        }
    }

    public static Node pushFirst(Node node, Node newNode) {
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

    public static Node pushLast(Node node, Node newNode) {
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

    public static void popFirst(Node node) {
        if (node.head.next != null) {
            node.head = node.head.next;
            node.head.prep = null;
        } else {
            node.head = null;
        }
    }

    public static void popLast(Node node) {
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
            ans.append(node.current.index);
            ans.append("  ");
            node.current = node.current.next;
        }
        System.out.print(ans);
        System.out.println();
    }

    public static int peekLast(Node node) {
        return node.rear.index;
    }
    
    public static int peek(Node node) {
        return node.head.index;
    }
}
