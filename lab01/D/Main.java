// by 11210162
import java.util.*;

public class Main {
	List<Long> Longlist = new ArrayList<>();
	List<String> selflist = new ArrayList<>(Arrays.asList(new String[]{"0","1","8"}));
	List<String> headlist = new ArrayList<>(Arrays.asList(new String[]{"1","6","8","9"}));
	List<String> list = new ArrayList<>(Arrays.asList(new String[]{"0","1","6","8","9"}));
	String[] revrselist = new String[]{"0","1","9","8","6"};

	public static void main(String args[]){
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()){
			Main m = new Main();
			String l=cin.next();
			String r=cin.next();
			int count=0;
			int ln = l.length();
			int rn = r.length();
			for(int i=ln;i<=rn;i++)
			{
				for(String s : ndit(m,i,true))
				{
					m.Longlist.add(Long.parseLong(s));
				}
			}
			long left = Long.parseLong(l);
			long right = Long.parseLong(r);
			for(long i : m.Longlist)
			{
				if(i<left || i>right)
					continue;
					count++;
			}
			System.out.println(count);
		}
	}
	public static List<String> ndit(Main m,int n,boolean head)
	{
		if(n==1)
			return new ArrayList<>(Arrays.asList(new String[]{"0","1","8"}));
		else if(n==2)
			{
				if(head)
					return new ArrayList<>(Arrays.asList(new String[]{"11","69","88","96"}));
				else
					return new ArrayList<>(Arrays.asList(new String[]{"00","11","69","88","96"}));
			}
		else {
			List<String> returnlist = new ArrayList<>();
			if(head)
				for(String s : m.headlist)
				{
					for(String a : ndit(m,n-2,false))
						returnlist.add(new StringBuilder(s).append(a).append(m.revrselist[m.list.indexOf(s)]).toString());
				}
			else
			{
				for(String s : m.list)
				{
					for(String a : ndit(m,n-2,false))
						returnlist.add(new StringBuilder(s).append(a).append(m.revrselist[m.list.indexOf(s)]).toString());
				}
			}
			return returnlist;
		}
	}
}