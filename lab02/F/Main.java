import java.util.Scanner;
/*
 * 
3
7 7
1 2 3 4 5 6 7
3 2
1 4 7
10 7
1 5 10 11 14 19 22 25 29 31
 */
public class Question6 {

	static int[] seat;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		int N,K;
		int r,l,mid;
		int dis=0;
		StringBuffer output=new StringBuffer();
	
		for(int loop=0;loop<T;loop++){
			N=input.nextInt();
			K=input.nextInt();
			seat=new int[N];
			for(int i=0;i<N;i++){
				seat[i]=input.nextInt();
			}
			l=0;		
			r=(seat[N-1]-seat[l])/(K-1);
			while(l<=r){	
				mid=(l+r)/2;
				if(check(mid,N,K)){
					dis=mid;
					l=mid+1;
				}else{
					r=mid-1;
				}		
			}
			
			output.append(dis);
			output.append("\n");
		}
		System.out.println(output);
	}
	
	static boolean check(int dis,int n,int k){
		int count=1;
		int actDis=0;
		for(int i=1;i<n;i++){
			actDis+=seat[i]-seat[i-1];
			if(actDis>=dis){
				count++;
				actDis=0;
			}
		}
		return count>=k;
	}

}
