import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int c=0;c<t;c++){
            int n = s.nextInt();
            int m = s.nextInt();
            linkedlist list1 = new linkedlist();
            linkedlist list2 = new linkedlist();
            for(int i=0;i<n;i++)
                list1.addLast(s.nextInt());
            for(int i=0;i<m;i++)
                list2.addLast(s.nextInt());
            StringBuilder result= new StringBuilder();
            linked tem1=list1.head;
            linked tem2=list2.head;
            linked tem;
            int i=0,j=0;
            while(tem1!=null || tem2!=null){
                if(tem1==null)
                {
                    tem=tem2;
                    tem2=tem2.next;
                }
                else if(tem2==null)
                {
                    tem=tem1;
                    tem1=tem1.next;
                }
                else if(tem1.value<tem2.value)
                {
                    tem=tem1;
                    tem1=tem1.next;
                }
                else
                {
                    tem=tem2;
                    tem2=tem2.next;
                }
                result.append(tem.value);
                result.append(" ");
            }
            System.out.println(result.toString());
        }

    }

    static class linked{
        int value;
        linked next;
        linked last;
        linked(linked last,int v,linked next){
            this.last=last;
            this.value=v;
            this.next=next;
        }
    }

    static class linkedlist{
        int length;
        linked head;
        linked tail;
        void addAfter(linked father,int v){
            if(father==tail)
                addLast(v);
            else
            {
                linked insert=new linked(father,v,father.next);
                father.next.last=insert;
                father.next=insert;
                length++;
            }
        }
        void addBefore(linked son,int v) {
            if(head==son)
                addFirst(v);
            else {
                linked insert = new linked(son.last, v, son);
                son.last.next = insert;
                son.last = insert;
                length++;
            }
        }
        void addLast(int v) {
            linked insert = new linked(tail, v, null);
            if(tail==null)
                head=insert;
            else
                tail.next=insert;
            tail=insert;
            length++;
        }
        void addFirst(int v){
            linked insert = new linked(null,v,head);
            if(head==null)
                tail=insert;
            else
                head.last=insert;
            head=insert;
            length++;
        }
        void add(int n,int v){
            if(n==0)
                addFirst(v);
            else if(n==length)
                addLast(v);
            else {
                addBefore(node(n),v);
            }
            length++;
        }
        linked node(int n){
            if(n<(length>>1))
            {
                linked x=head;
                for(int i=0;i<n;i++)
                    x=x.next;
                return x;
            }
            else{
                linked x=tail;
                for(int i=length-1;i>n;i--)
                    x=x.last;
                return x;
            }
        }
    }
}

