import java.util.Scanner;
/*
1
6
1 2 2 4 5 6
2
2
7
or
1
10
1 2 2 3 3 3 3 4 5 6
2
2
3
 */
public class Question7 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		int N, Q,x;
		int s[];
		StringBuffer output=new StringBuffer();
		for (int loop = 0; loop < T; loop++) {
			N = input.nextInt();
			s = new int[N];
			for (int i = 0; i < N; i++) {
				s[i] = input.nextInt();
			}
			Q=input.nextInt();
			
			for(int line=0;line<Q;line++){
				x=input.nextInt();
				output.append(index(s,x));
				output.append("\n");
			}
		}
		System.out.println(output);

	}

	static int index(int[] array, int value) {
		int l = 0;
		int r = array.length - 1;
		int mid;
		while (l < r) {
			mid = (l + r) / 2;
			if (array[mid] == value) {
				if (mid == 0) {
					return mid+1;
				} else {
					int i=mid;
					while(array[i-1]==array[i]){
						i--;
					}
					return i+1;
				}
			}
			if (array[mid] < value) {
				l = mid + 1;
			}
			if (array[mid] > value) {
				r = mid - 1;
			}
		}
		return -1;
	}

}
