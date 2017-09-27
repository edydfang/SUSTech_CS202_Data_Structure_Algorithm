
import java.util.Scanner;
/*
 * 
2
5 9
1 2 3 6 7
5 8
1 2 3 6 7
 */
public class Question4 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int T = input.nextInt();
		StringBuffer output = new StringBuffer();
		int m,n;
		for (int loop = 0; loop < T; loop++) {
			n=input.nextInt();
			m=input.nextInt();
			int array[] = new int[n];
			for (int i = 0; i < n; i++) {
				array[i] = input.nextInt();
			}
			
			output.append(triple(array,m));
			output.append("\n");
		}
		System.out.println(output);

	}
	
	static String triple(int array[], int m){
		int l, r, mid;
		
		for (int i = 0; i < array.length; i++) {
			for (int j = i + 1; j < array.length; j++) {
				l = j + 1;
				r = array.length - 1;

				while (l < r) {
					mid = (l + r) / 2;
					if ((array[i] + array[j] + array[mid]) == m) {
						return "YES";				
					} else if ((array[i] + array[j] + array[mid]) < m) {
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				}

			}
		}
		return "NO";
	}

}
