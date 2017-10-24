import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;
 
public class Main {
    static int len;
    static String text;
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
 
    static int[] Next(){
        int[] Next = new int[len+1];
        char[] s = text.toCharArray();
        if(len==0){
            Next[0] = 0;
            return  Next;
            }
        Next[0] = Next[1] = 0;
        int j = 0;
        for (int i=1; i<text.length(); i++) {
            while (j>0 && s[j]!=s[i]) {
                j  = Next[j];
            }
            if (s[j]==s[i]) {
                j++;
            }
            Next[i+1] = j;
        }
        return Next;
    }
    static long solve() {
        long ans = 0;
        int[] next = Next();
        long[] cnt = new long[len+1];
        for (int i=1; i<=len; i++){
             cnt[i] = 1;
         }     
        cnt[0] = 0;
        for (int i=len; i>0; i--) {
            cnt[next[i]] += cnt[i];
            ans+=(long)i*cnt[i];
        }
        return ans;
    }
    public static void main(String[] args) {
         InputStream inputStream = System.in;
         InputReader in = new InputReader(inputStream);
         OutputStream outputStream = System.out;
         PrintStream out = new PrintStream(outputStream);
         int T = in.nextInt();
         long ans;
         while(T-->0) {
             len = in.nextInt();
             text = in.next();
             ans = solve();
             out.println(ans);
         }
         out.close();
    }
 
}