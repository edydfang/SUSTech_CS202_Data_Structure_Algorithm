import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(;t>0;t--){
            String str=s.next();
            List<linkedlist> array = new ArrayList<>();
            int p=(int)Math.sqrt(str.length());
            for(int i=0;i<str.length();i++)
            {
                if(i%p==0)
                {
                    array.add(new linkedlist());
                }
                array.get(i/p).addLast(str.charAt(i));
            }
            int n=s.nextInt();
            for(;n>0;n--)
            {
                int o=s.nextInt();
                if(o==1)
                {
                    char v= s.next().charAt(0);
                    int k = s.nextInt();
                    int num=0;
                    int j=0;
                    for(;j<array.size();j++)
                    {
                        if(num+array.get(j).length>=k)
                            break;
                        num+=array.get(j).length;
                    }
                    array.get(j).add(k-num-1,v);
                }
                else
                {
                    int k = s.nextInt();
                    int num=0;
                    int j=0;
                    for(;j<array.size();j++)
                    {
                        if(num+array.get(j).length>=k)
                            break;
                        num+=array.get(j).length;
                    }
                    System.out.println(array.get(j).node(k-num-1).value);
                }
            }
        }

    }
    static class linkedlist{
        int length;
        linked head;
        linked tail;
        void addAfter(linked father,char v){
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
        void addBefore(linked son,char v) {
            if(head==son)
                addFirst(v);
            else {
                linked insert = new linked(son.last, v, son);
                son.last.next = insert;
                son.last = insert;
                length++;
            }
        }
        void addLast(char v) {
            linked insert = new linked(tail, v, null);
            if(tail==null)
                head=insert;
            else
                tail.next=insert;
            tail=insert;
            length++;
        }
        void addFirst(char v){
            linked insert = new linked(null,v,head);
            if(head==null)
                tail=insert;
            else
                head.last=insert;
            head=insert;
            length++;
        }
        void add(int n,char v){
            if(n==0)
                addFirst(v);
            else if(n==length)
                addLast(v);
            else {
                addBefore(node(n),v);
            }
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

    static class linked{
        char value;
        linked next;
        linked last;
        linked(linked last,char v,linked next){
            this.last=last;
            this.value=v;
            this.next=next;
        }
    }
}