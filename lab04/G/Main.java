import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
         int T = sc.nextInt();
         sc.nextLine();
         for (int i = 0; i < T; i++) {    
         Calculator(convertToPostfix(sc.nextLine()));
         }
    }

    public static boolean isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')';
    }

    public static boolean isLowerPrecedence(char op1, char op2) {
        switch (op1) {
        case '+':
        case '-':
            return !(op2 == '+' || op2 == '-');

        case '*':
        case '/':
            return op2 == '^' || op2 == '(';

        case '^':
            return op2 == '(' || op2 == '^';

        case '(':
            return true;

        default:
            return false;
        }
    }

    public static ArrayList<String> convertToPostfix(String infix) {
        Stack<String> stack = new Stack<String>();
        ArrayList<String> ans = new ArrayList<String>();
        char c;
        for (int i = 0; i < infix.length(); i++) {
            c = infix.charAt(i);
            if (!isOperator(c)) {
                String x = String.valueOf(c);
                while(i < infix.length()-1&&!isOperator(infix.charAt(i+1))) {
                    x = x + infix.charAt(i+1); 
                    i++;
                }
                ans.add(x);
            } else {
                if (c == '(') {
                    stack.push(String.valueOf(c));
                } else if (c == ')') {
                    while (!stack.isEmpty() && !stack.peek().equals("(")) {
                        ans.add(stack.pop());
                    }
                    stack.pop();
                } else if (!stack.isEmpty() && isLowerPrecedence(stack.peek().charAt(0), c)) {
                    stack.push(String.valueOf(c));
                } else if (!stack.isEmpty() && !isLowerPrecedence(stack.peek().charAt(0), c)) {
                    while(!stack.isEmpty() && !isLowerPrecedence(stack.peek().charAt(0), c))
                        ans.add(stack.pop());
                    stack.push(String.valueOf(c));
                    
                } else {
                    stack.push(String.valueOf(c));
                }
            }

        }

        while (!stack.isEmpty())
            ans.add(stack.pop());

        return ans;
    }

    public static void Calculator(ArrayList<String> st) {
        Stack<String> stack = new Stack<String>();
        for (String a : st) {
            if (!isOperator(a.charAt(0))) {
                stack.push(a + "");
            } else {
                int y = Integer.parseInt(stack.pop());
                int x = Integer.parseInt(stack.pop());
                int z = 0;
                switch (a) {
                case "+":
                    z = x + y;
                    break;
                case "-":
                    z = x - y;
                    break;
                case "*":
                    z = x * y;
                    break;
                case "/":
                    z = x / y;
                    break;
                case "^":
                    z = (int) Math.pow(x, y);
                    break;
                }
                stack.push(z + "");

            }
        }
        while (!stack.isEmpty()) {
            System.out.println(stack.pop());
        }
    }

}
