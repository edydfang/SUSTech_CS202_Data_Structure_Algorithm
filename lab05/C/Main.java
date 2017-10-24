import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.StringTokenizer;
 
public class Main    {
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
    final static int[] Next(String s) {
        int[] next = new int[s.length()];
        char[] T = s.toCharArray();
        next[0] = -1;
        for (int i = 1; i<T.length; i++){
            int j = next[i - 1];
            while (j >= 0 && T[i - 1] != T[j]) j = next[j];
            if (j >= 0 &&  T[i - 1] == T[j]) next[i] = j + 1;
            else next[i] = 0;
        }
        return next;
    }
      static int solve(String text, String pattern) {
            int counter = 0;
            int[] next = Next(pattern);
            char[] T = text.toCharArray();
            char[] P = pattern.toCharArray();
            int pos = 0;
            int m = text.length();
            int n = pattern.length();
            for (int index = 0; index<text.length(); ++index){
                pos = 0;
                int iter = index;
                while (pos<pattern.length() && iter<text.length()){
                    if (T[iter] == P[pos]){ ++iter; ++pos; }
                    else{
                        if (pos == 0) ++iter;
                        else pos = next[pos - 1] + 1;
                    }
                }
                if (pos == P.length && (iter - index) == P.length) ++counter;
            }
            return counter;
        }
     
    public static void main(String[] args) {
         InputStream inputStream = System.in;
         InputReader in = new InputReader(inputStream);
         OutputStream outputStream = System.out;
         PrintStream out = new PrintStream(outputStream);
         int T = in.nextInt();
         while(T-->0) {
             int len = in.nextInt();
             String text = in.next();
             int len2 = in.nextInt();
             String pattern = in.next();
             out.println(solve(text, pattern));
         }
         out.close();
    }
 
}