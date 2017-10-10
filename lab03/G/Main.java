import java.util.*;
public class Main {
    static final int part=10;
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(;t>0;t--){
            int n=s.nextInt();
            StringBuilder result=new StringBuilder();
            ArrayList<linkedlist> array = new ArrayList<linkedlist>();
            for(int i=0;i<10000/part+1;i++)
                array.add(new linkedlist());
            int v =s.nextInt();
            int v2=v,v3=v;
            array.get(v/part).addFirst(v);
            linked mid=array.get(v/part).head;
            result.append(mid.value+" ");
            for(int i=1;i<n;i++)
            {
                v =s.nextInt();
                insert(array,v,mid);
                if(i%2==1)
                    v2=v;
                else if(i%2==0)
                    v3=v;
                if((i&1)==0)
                {
                    int midval=mid.value;
                    if(midval>v2 && midval>v3)
                    {
                        if(mid.last!=null)
                            mid=mid.last;
                        else
                        {
                            int j=midval/part-1;
                            while(array.get(j).tail==null)
                                j--;
                            mid=array.get(j).tail;
                        }
                    }
                    else if(midval<v2 && midval<v3)
                    {
                        if(mid.next!=null)
                            mid=mid.next;
                        else
                        {
                            int j=midval/part+1;
                            while(array.get(j).head==null)
                                j++;
                            mid=array.get(j).head;
                        }
                    }
                    result.append(mid.value+" ");
                }
            }
            System.out.println(result);
        }
    }
    public static void insert(ArrayList<linkedlist> array,int v,linked mid)
    {
        linkedlist list = array.get(v/part);
        linked tem;
        tem=list.head;
        while(tem!=list.tail && tem.value<v)
            tem=tem.next;
        if(tem==null)
            list.addFirst(v);
        else if(tem.value<v)
            list.addAfter(tem,v);
        else
            list.addBefore(tem,v);
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
