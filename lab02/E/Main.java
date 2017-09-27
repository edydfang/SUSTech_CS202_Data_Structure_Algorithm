import java.util.Scanner;
/*
 * 
2
3 2 1
3 3 3
5 7 2
1 2 3 4 5
 */
public class Question5 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		int N, K, X;
		int a[],f[];
		StringBuffer output=new StringBuffer();
		for (int loop = 0; loop < T; loop++) {
			N = input.nextInt();
			K = input.nextInt();
			X = input.nextInt();
			a=new int[N];
			f=new int[N];
			for(int i=0;i<N;i++){
				a[i]=input.nextInt();
				f[i]=1;
			}
			int house;
			for(int i=X;i<K+X;i++){
				house=(i)%N;
				f[house]=a[house]*f[house];
			}
			for(int i=0;i<N;i++){
				output.append(String.valueOf(f[i]));
				output.append(" ");
			}
			output.append("\n");
			
		}
		System.out.println(output);

	
	}

}
