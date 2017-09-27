import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int T = input.nextInt();
		long N;
		for (int loop = 0; loop < T; loop++) {
			N = input.nextInt();

			long sum = 0;

			for (long i = 1; i <= N; i++) {
				sum += i * i;
			}
			System.out.println(sum);
		}

	}

}
