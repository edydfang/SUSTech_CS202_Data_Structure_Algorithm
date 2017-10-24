import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.StringTokenizer;
 
public class Main{
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
    static int[] getnext( char T[])  
    {  
        int len = T.length;
        int[] next = new int[len+1];
        int i = 0, j = -1;  
        next[0] = -1;  
        while(i < len)  
        {  
            if(j == -1 || T[i] == T[j])  
            {  
                i++;j++;  
                next[i] = j;  
            }  
            else 
                j = next[j];  
        }
        return next;  
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub
         InputStream inputStream = System.in;
         InputReader in = new InputReader(inputStream);
         OutputStream outputStream = System.out;
         PrintStream out = new PrintStream(outputStream);
         int T = in.nextInt();
         while(T-->0) {
             int len = in.nextInt();
             String s = in.next();  
             int[] next = getnext(s.toCharArray());  
             int length = len - next[len];  
             out.println(length); 
         }
         out.close();
    }
 
}