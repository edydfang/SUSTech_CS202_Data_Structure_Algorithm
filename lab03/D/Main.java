import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int c=0;c<t;c++){
            Map<Integer,Integer> mapa=new HashMap<>();
            Map<Integer,Integer> mapb=new HashMap<>();
            Map<Integer,Integer> mapr=new HashMap<>();
            int n = s.nextInt();
            for(int i=0;i<n;i++)
            {
                int coe=s.nextInt();
                int exp=s.nextInt();
                mapa.put(exp,coe);
            }
            int m = s.nextInt();
            for(int i=0;i<m;i++)
            {
                int coe=s.nextInt();
                int exp=s.nextInt();
                mapb.put(exp,coe);
            }
            for(int i : mapa.keySet())
                for(int j : mapb.keySet())
                {
                    if(mapr.containsKey(i+j))
                        mapr.put(i+j,mapr.get(i+j)+mapa.get(i)*mapb.get(j));
                    else
                        mapr.put(i+j,mapa.get(i)*mapb.get(j));
                }
            StringBuilder sb=new StringBuilder();
            List<Integer> list=new ArrayList<>(mapr.keySet());
            Collections.sort(list);
            for(int i:list)
            {
                String x;
                String symbol="+";
                String number;
                int coe=mapr.get(i);
                int exp=i;
                if(exp==0)
                    x="";
                else if(exp==1)
                    x="x";
                else
                    x="x^"+exp;

                if(coe==1)
                    number="";
                else
                    number=String.valueOf(coe);

                if(exp==0 && coe==1)
                    number="1";

                sb.append(symbol+number+x);
            }
            if(sb.length()==0)
                sb.append(0);
            else if(sb.charAt(0)=='+')
                sb.replace(0,1,"");

            System.out.println(sb);
        }

    }
    static class linked{
        int coefficient;
        int exponent=Integer.MAX_VALUE;
        linked next;
        linked last;
        public linked(int c,int e,linked l){
            this.coefficient=c;
            this.exponent=e;
            this.last=l;
        }
        public linked(linked l){
            this.last=l;
        }
        public linked(){}
    }
}
