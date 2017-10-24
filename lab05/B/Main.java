import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
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
        public char nextChar() {
            return next().charAt(0);
        }
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub
         InputStream inputStream = System.in;
         InputReader in = new InputReader(inputStream);
         OutputStream outputStream = System.out;
         PrintStream out = new PrintStream(outputStream);
         int T = in.nextInt();
         while(T-->0) {
             String s = in.next();
             int n = in.nextInt();
             int pos = 0;
             int index1 ;
             int index2 ;
             StringBuilder sb = new StringBuilder();
             while(n-->0){
                 switch(in.next()) {
                 case "Add" :   
                            char x = in.nextChar();
                            pos = in.nextInt();
                            s = s.substring(0, pos) + x + s.substring(pos, s.length());
                            sb.append(s).append("\n");
                            break;
                 case "Delete" :    
                            pos = in.nextInt();
                            s = s.substring(0,pos++) + s.substring(pos,s.length());
                            sb.append(s).append("\n");
                            break;
                 case "Sstr" :   
                            index1 = in.nextInt();
                            index2 = in.nextInt();
                            sb.append(s.substring(index1, index2+1)).append("\n");
                            break;
                 case "Reverse" :
                            index1 = in.nextInt();
                            index2 = in.nextInt();
                            char[] c1 = s.toCharArray();
                            char[] c2 = s.toCharArray();
                            int op = 0;
                            for(int i = index1; i <= index2; i++) {
                                c2[i] = c1[index2-(op++)];
                            }
                            s = String.valueOf(c2);
                            sb.append(s).append("\n");
                 }
             }
             out.print(sb.toString());
         }
         out.close();
    }
}