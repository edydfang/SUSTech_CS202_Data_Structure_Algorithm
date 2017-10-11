import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int c=0;c<t;c++){
            int n = s.nextInt();
            linked head=new linked();
            linked tem=head;
            for(int i=0;i<n;i++)
            {
               tem.next=new linked(s.nextInt(),tem);
               tem=tem.next;
            }
            linked tail=new linked();
            tem.next=tail;
            tail.last=tem;
            int m = s.nextInt();
            for(int i=0;i<m;i++)
            {
                int o=s.nextInt();
                switch (o){
                    case 1:
                    {
                        int k=s.nextInt();
                        int v=s.nextInt();
                        tem=head.next;
                        for(int j=0;j<k;j++)
                        {
                            System.out.print(tem.value+" ");
                            tem=tem.next;
                        }
                        linked insert=new linked(v,tem.last);
                        insert.next=tem;
                        tem.last.next=insert;
                        tem.last=insert;
                        tem=insert;
                        while(tem.next!=null)
                        {
                            System.out.print(tem.value+" ");
                            tem=tem.next;
                        }
                        System.out.println();
                    }break;
                    case 2:
                    {
                        int k=s.nextInt();
                        tem=head.next;
                        for(int j=0;j<k;j++)
                        {
                            System.out.print(tem.value+" ");
                            tem=tem.next;
                        }
                        tem.last.next=tem.next;
                        tem.next.last=tem.last;
                        tem=tem.next;
                        while(tem.next!=null)
                        {
                            System.out.print(tem.value+" ");
                            tem=tem.next;
                        }
                        System.out.println();
                    }break;
                    case 3:
                    {
                        int k=s.nextInt();
                        int v=s.nextInt();
                        tem=head;
                        for(int j=0;j<k;j++)
                        {
                            tem=tem.next;
                            System.out.print(tem.value+" ");
                        }
                        tem.next.value=v;
                        tem=tem.next;
                        while(tem.next!=null)
                        {
                            System.out.print(tem.value+" ");
                            tem=tem.next;
                        }
                        System.out.println();
                    }break;
                    case 4:
                    {
                        tem=tail;
                        while(tem!=null)
                        {
                            linked swap = tem.last;
                            tem.last=tem.next;
                            tem.next=swap;
                            tem=tem.next;
                        }
                        tem=tail;
                        tail=head;
                        head=tem;
                        tem=head.next;
                        while(tem.next!=null)
                        {
                            System.out.print(tem.value+" ");
                            tem=tem.next;
                        }
                        System.out.println();
                    }break;
                }
            }
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
        public linked(){}
    }
}

