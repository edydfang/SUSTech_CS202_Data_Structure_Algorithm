#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <iomanip>
#include <string>
#include <cmath>
#include <queue>
#include <map>
 
const int MAXC = 1000000 + 10; 
const int MAXM = 1000 + 10; 
const int MAXN = 1000000 + 10;
const int N=2000, L=2000;
using namespace std;
struct Block_List {
    struct Node {
        char str[L];
       
        int next, size;
        void init(){
             memset(str, 0, sizeof(str));
             next = -1;
             size = 0;
        }
    }list[N];
    int head, tot;
 
    void init(char str[]){
         head = tot = 0;
         list[tot++].init();
         for (int i = 0, cur = head; str[i]; cur = list[cur].next){
             for (int j = 0; j < L && str[i]; j++, i++){
                 list[cur].str[j] = str[i];
                 list[cur].size++;
             }
              
             if (str[i]){
                list[tot].init();
                list[cur].next = tot++; 
             }
         } 
         for (int cur = head; cur != -1; cur = list[cur].next)
         if (list[cur].size == L) split(cur);
    }
 
    void split(int x){
         list[tot].init();
         for (int i = L / 2; i < L; i++){
             list[tot].str[i - L/2] = list[x].str[i];
             list[tot].size++;
             list[x].size--;
             list[x].str[i] = 0;
         }
         list[tot].next = list[x].next;
         list[x].next = tot++;
    }
    void insert(int pos, char val){
         int cur = head;
        
         while (pos - list[cur].size > 0 && list[cur].next != -1){
               pos -= list[cur].size;
               cur = list[cur].next; 
         }
         if (pos >= list[cur].size) list[cur].str[list[cur].size] = val;
         else {
             
              for (int i = list[cur].size; i > pos; i--) list[cur].str[i] = list[cur].str[i - 1] ;
              list[cur].str[pos] = val;
         }
         list[cur].size++;
         if (list[cur].size == L) split(cur);
    }
    char find(int pos){
         int cur = head;
         while ( pos - list[cur].size > 0){
               pos -= list[cur].size;
               cur = list[cur].next;
         }
         return list[cur].str[pos - 1];
    }
}A;
char str[MAXN];
int n, T;
 
int main() {
    // freopen("test.in",  "r",  stdin);
    // freopen("test.ans",  "w",  stdout); 
    scanf("%d", &T);
    while (T--){
         
    scanf("%s%d", str, &n);
    A.init(str);
    for (int i = 0; i < n; i++){
        int pos, op;
        scanf("%d", &op);
        if (op == 1){
           char S[2]; 
           scanf("%s%d", S, &pos);
           A.insert(pos - 1, S[0]);
        } else {
           scanf("%d", &pos);
           printf("%c\n", A.find( pos ));
        }
    } 
    }
    return 0;
}
