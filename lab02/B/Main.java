import java.util.Scanner;

//

public class Question2 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int T = input.nextInt();
		StringBuffer output = new StringBuffer();
		int n,m;

		for (int loop = 0; loop < T; loop++) {			
			n=input.nextInt();
			m=input.nextInt();
			int array[] = new int[n];
			for (int i = 0; i < n; i++) {
				array[i] = input.nextInt();
			}
			output.append(include(array, m));
			output.append("\n");
		}
		System.out.println(output);
	}

	static String include(int[] array, int value) {
		int l = 0;
		int r = array.length - 1;
		int mid;
		while (l < r) {
			mid = (l + r) / 2;
			
			if (array[mid] == value) {
				return "YES";
			} else if (array[mid] < value) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		return "NO";
	}

}
