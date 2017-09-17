// by 11210162
import java.util.*;
public class Main {
	public static void main(String args[]){
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		String[] order=new String[]{"3","4","5","6","7","8","9","10","J","Q","K","A","2","WJ","RJ"};
		Map<String, Integer> map=new HashMap<>();
		for(int i=0;i<15;i++)
			map.put(order[i], i);
		int[] power=new int[]{0,1,10,100,1000};
		while (cin.hasNext()){
			int[] card=new int[15];
			int[] weight=new int[15];
			String player=cin.next();
			int n=player.equals("Dizhu")?20:17;
			for(int i=0;i<n;i++)
			{
				String c = cin.next();
				card[map.get(c)]++;
			}
			weight[14]=card[14]*100001;
			weight[13]=card[13]*100000;
			Map<Integer, int[]> result=new HashMap<>();
			result.put(weight[14], new int[]{card[14],14});
			result.put(weight[13], new int[]{card[13],13});
			for(int i=0;i<13;i++)
			{
				weight[i]=card[i]*power[card[i]]*(i+1);
				result.put(weight[i], new int[]{card[i],i});
			}
			Arrays.sort(weight);
			for(int i=14;i>-1;i--)
			{
				if(weight[i]==0)
					break;
				for(int j=0;j<result.get(weight[i])[0];j++)
					System.out.print(order[result.get(weight[i])[1]]+" ");
			}
			System.out.println();
		}
	}
}
