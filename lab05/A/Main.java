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
             int n = s.length();
             out.println(n*(n+1)/2);
         }
         out.close();
    }
 
}