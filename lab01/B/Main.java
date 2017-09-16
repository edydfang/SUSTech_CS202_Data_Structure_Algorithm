
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		String a;
		String b;

		
		
		while (cin.hasNext())
		{
			a = cin.next();
			b = cin.next();
			int num = 0;
			int[] array_a = new int[1001];
			int[] array_b = new int[1001];
			int[] array_c = new int[1010];
			
			
			for (int i = 0; i < a.length(); i++) {
				array_a[i] = Character.getNumericValue(a.charAt(a.length() - 1 - i));
			}
			for (int j = 0; j < b.length(); j++) {
				array_b[j] = Character.getNumericValue(b.charAt(b.length() - 1 - j));
			}
			if(a.length()<b.length()) {
				num = b.length();
			}else {
				num = a.length();
			}
			
			for (int k = 0; k <num; k++) {
				array_c[k] = array_c[k] + (array_a[k] + array_b[k]) % 10;
				array_c[k + 1] = array_c[k + 1] + (array_a[k] + array_b[k]) / 10;
				if(array_c[k] >=10) {
					array_c[k + 1] = array_c[k + 1] +array_c[k]/10;
					array_c[k] = array_c[k] % 10;
				}
		
			}
			
			if(array_c[num]!=0) {
				num++;
			}
			
			

/*			for (int h = array_c.length - 1; h >= 0; h--) {
				if (array_c[h] != 0) {
					break;
				}
				flag--;
			}*/
			for (int q = num - 1; q >= 0; q--) {
				System.out.print(array_c[q]);
			}
			System.out.print("\n");
		}

	}
}
