import java.util.Scanner;
/*
4
3 5
4 4
5 7
12 8
 */
public class Question8 {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		StringBuffer output = new StringBuffer();
		int T = input.nextInt();
		int x, y, x1, y1,sum;
		int count;

		for (int loop = 0; loop < T; loop++) {
			x = input.nextInt();
			y = input.nextInt();
			x1 = x;
			y1 = y;
			sum=x+y;
			count = 1;

			while (x != y) {
				x=cal(x,y);
				y=sum-x;
				
				x1=cal(x1,y1);
				y1=sum-x1;
				x1=cal(x1,y1);
				y1=sum-x1;
				
				if(x==x1&&x!=y){
					count=-1;
					break;
				}
				count++;
			}

			output.append(String.valueOf(count));
			output.append("\n");
		}

		System.out.println(output);
	}
	
	static int cal(int x,int y){
		if (x > y) {
			x = x - y;
			y = y + y;
		} else if (x < y) {
			y = y - x;
			x = x + x;
		}	
		return x;
	}
}
