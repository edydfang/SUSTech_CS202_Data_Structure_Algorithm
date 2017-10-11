import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int c=0;c<t;c++){
            int n = s.nextInt();
            int k = s.nextInt();
            linked head=new linked();
            linked tem=head;
            for(int i=0;i<n;i++)
            {
               tem.next=new linked(i,tem);
               tem=tem.next;
            }
            tem.next=head.next;
            head.next.last=tem;
            tem=head.next;
            int count=0;
            while(tem.next!=tem)
            {
                if(count==k)
                {
                    tem.last.next=tem.next;
                    tem.next.last=tem.last;
                    count=0;
                    tem=tem.next;
                }
                else
                {
                    tem=tem.next;
                    count++;
                }
            }
            System.out.println(tem.value);
        }

    }
    static class linked{
        int value;
        linked next;
        linked last;
        public linked(int v,linked l){
            this.value=v;
            this.last=l;
        }
        public linked(linked l){
            this.last=l;
        }
        public linked(int v)
        {
            this.value=v;
        }
        public linked(){}
    }
}

