// by 11210162
import java.text.DecimalFormat;
import java.util.*;

public class Main {
	public static void main(String args[]){
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		DecimalFormat df=new DecimalFormat("0.000000"); 
		Comparator<rope> avecmp = new Comparator<rope>(){  	   
	        @Override  
	        public int compare(rope r1, rope r2) {
	        	if(r1 == null && r2 == null) {  
	        	    return 0;  
	        	}  
	        	if(r1 == null) {  
	        	    return -1;  
	        	}  
	        	if(r2 == null) {  
	        	    return 1;  
	        	}  
	        	if(r1.avelen > r2.avelen) {  
	        	    return 1;  
	        	}  
	        	if(r2.avelen > r1.avelen) {  
	        	    return -1;  
	        	} 
	        	return 0;  
	        }  
	    };  
	    Comparator<rope> fucmp = new Comparator<rope>(){  	   
	        @Override  
	        public int compare(rope r1, rope r2) {  
	            if (r2.futruelen>r1.futruelen)
	            	return 1;
	            if (r2.futruelen<r1.futruelen)
	            	return -1;
	            else return 0;
	        }  
	    };  
		while (cin.hasNext()){
			int n=cin.nextInt();
			int k=cin.nextInt();
 
			Queue<rope> acceptque = new PriorityQueue<rope>(11,fucmp);
			for(int i=0;i<n;i++)
			{
				acceptque.add(new rope((int)(Double.valueOf(cin.next())*100000)));
			}
			
			for(int i=0;i<k;i++)
			{
				rope temrope = acceptque.poll();
				temrope.accept();
				acceptque.add(temrope);
			}
			
			List<rope> list = new ArrayList<rope>();
			list.addAll(acceptque);
			Collections.sort(list, avecmp);
			double longest = list.get(0).avelen/100000.0;
			String rString= df.format(longest).substring(0, 4);
			System.out.println(rString);
		}
	}
	static class rope{
		int num = 0;
		int length;
		int avelen=Integer.MAX_VALUE;
		int futruelen;
		public rope(int length) {
			this.length=length;
			this.futruelen=length;
		}
		public void accept()
		{
			this.num++;
			this.avelen=length/num;
			this.futruelen=length/(num+1);
		}
	}
}