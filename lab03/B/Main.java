import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int c=0;c<t;c++){
            int n = s.nextInt();
            linked list1 = new linked();
            linked tem=list1;
            for(int i=0;i<n;i++)
            {
                tem.next=new linked(s.nextInt(),s.nextInt(),tem);
                tem=tem.next;
            }
            tem.next=new linked(tem);
            int m = s.nextInt();
            linked list2 = new linked();
            tem=list2;
            for(int i=0;i<m;i++)
            {
                tem.next=new linked(s.nextInt(),s.nextInt(),tem);
                tem=tem.next;
            }
            tem.next=new linked(tem);
            linked tem1=list1,tem2=list2;
            while(tem1.next!=null || tem2.next!=null)
            {
                if(tem1.next==null || tem1.exponent>tem2.exponent)
                {
                    linked add=new linked(0,tem2.exponent,tem1.last);
                    tem1.last.next=add;
                    add.next=tem1;
                    tem1.last=add;
                    tem2=tem2.next;
                }
                else if(tem2.next==null || tem1.exponent<tem2.exponent)
                {
                    linked add=new linked(0,tem1.exponent,tem2.last);
                    tem2.last.next=add;
                    add.next=tem2;
                    tem2.last=add;
                    tem1=tem1.next;
                }
                else
                {
                    tem1=tem1.next;
                    tem2=tem2.next;
                }
            }
            tem1=list1.next;
            tem2=list2.next;
            StringBuilder result= new StringBuilder();
            String x;
            String number;
            String symbol;
            while (tem1.next!=null)
            {
                int coefficient = tem1.coefficient+tem2.coefficient;
                int exponent = tem1.exponent;
                if(coefficient==0)
                {
                    tem1=tem1.next;
                    tem2=tem2.next;
                    continue;
                }
                if(exponent==0)
                {
                    x="";
                }
                else if(exponent==1)
                    x="x";
                else
                    x="x^"+exponent;

                if(coefficient>0)
                    symbol="+";
                else
                    symbol="";

                if(coefficient==1)
                    number="";
                else if(coefficient==-1)
                    number="-";
                else
                    number=String.valueOf(coefficient);

                if(exponent==0 && Math.abs(coefficient)==1)
                {
                    number=String.valueOf(coefficient);
                }

                result.append(symbol+number+x);
                tem1=tem1.next;
                tem2=tem2.next;
            }
            if(result.length()==0)
                result.append(0);
            else if(result.charAt(0)=='+')
                result.replace(0,1,"");
            System.out.println(result.toString());
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

