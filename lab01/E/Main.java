// by 11210162
import java.util.*;

public class Main{
	
	public static void main(String args[]){
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()){
			int n=0;
			int ax=cin.nextInt();
			int ay=cin.nextInt();
			int bx=cin.nextInt();
			int by=cin.nextInt();
			int dy=Math.abs(by-ay);
			int dx=Math.abs(bx-ax);
			int temp;
			if(dx>dy)
			{
				temp = dx;
				dx = dy;
				dy = temp;
			}
		    while(dx!=0)
		    {    
		        temp = dx;
		        dx = dy % dx;
		        dy = temp;
		    }
		    n=dy==0?0:(dy-1);
			System.out.println(n);
		}
	}
}