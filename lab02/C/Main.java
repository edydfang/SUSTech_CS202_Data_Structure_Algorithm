
import java.util.Scanner;

public class Question3 {
	
	/*
3
4 5
1 2 3 4
4 9
2 7 11 15
3 6
1 2 3
	 */
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);

		int T = input.nextInt();
	
		StringBuffer output = new StringBuffer();
		int count,n,m;

		for (int loop = 0; loop < T; loop++) {

			n=input.nextInt();
			m=input.nextInt();
			int array[] = new int[n];
			for (int i = 0; i < n; i++) {
				array[i] = input.nextInt();
			}
			count = 0;			
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if ((array[i] + array[j]) == m) {
						count++;
					}
				}
			}
			output.append(String.valueOf(count));
			output.append("\n");
		}	
		System.out.println(output);
	}

}
