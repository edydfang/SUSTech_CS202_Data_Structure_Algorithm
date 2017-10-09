#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int N = 2000000 + 10, block_sz = 4000 + 100, block_num = 4000 + 10;

queue<int> que;
int head;
char str[N];
struct block
{
    int sz, next;
    bool rev;
    char s[block_sz];
    void init()
    {
        sz = 0, next = -1, rev = 0;
    }
} g[block_num];
int new_block()
{
    int t = que.front();que.pop();
    g[t].init();
    return t;
}
void del_block(int t)
{
    que.push(t);
}
void block_update(int idx)
{
    if(g[idx].rev)
    {
        reverse(g[idx].s, g[idx].s + g[idx].sz);
        g[idx].rev = 0;
    }
}
void block_split(int idx, int k)
{
    if(idx == -1 || k == g[idx].sz) return;
    block_update(idx);
    int tot = new_block();
    memcpy(g[tot].s, g[idx].s + k, sizeof(char) * (g[idx].sz - k));
    g[tot].sz = g[idx].sz - k, g[idx].sz = k;
    g[tot].next = g[idx].next, g[idx].next = tot;
}
void block_merge(int idx)
{
    for(int i = idx; i != -1; i = g[i].next)
    {
        for(int j = g[i].next; j != -1; j = g[j].next)
        {
            if(g[i].sz + g[j].sz <= block_sz)
            {
                block_update(i), block_update(j);
                memcpy(g[i].s + g[i].sz, g[j].s, sizeof(char) * g[j].sz);
                g[i].sz += g[j].sz, g[i].next = g[j].next;
                del_block(j);
            }
            else break;
        }
    }
}
void block_init()
{
    while(! que.empty()) que.pop();
    for(int i = 0; i < block_num; i++) que.push(i);
    head = new_block();
}
void block_locate(int &idx, int &k)
{
    while(idx != -1 && k > g[idx].sz) k -= g[idx].sz, idx = g[idx].next;
}
void block_insert(int k, int n, char *str)
{
    int idx = head;
    block_locate(idx, k);
    block_split(idx, k);
    int i = 0;
    while(i < n)
    {
        int sz = min(block_sz, n - i);
        int tot = new_block();
        memcpy(g[tot].s, str + i, sizeof(char) * sz);
        g[tot].sz = sz;
        g[tot].next = g[idx].next, g[idx].next = tot, idx = g[idx].next;
        i += sz;
    }
    block_merge(head);
}
void block_delete(int l, int r)
{
    int idx = head;
    block_locate(idx, l);
    block_split(idx, l);
    int st = idx, st_next = g[idx].next;

    idx = head;
    block_locate(idx, r);
    block_split(idx, r);
    int en = idx, en_next = g[idx].next;

    for(int i = st_next; i != en_next; i = g[i].next) del_block(i);
    g[st].next = en_next;
    block_merge(head);
}
void block_rev(int l, int r)
{
    int idx = head;
    block_locate(idx, l);
    block_split(idx, l);
    int st = idx, st_next = g[idx].next;

    idx = head;
    block_locate(idx, r);
    block_split(idx, r);
    int en = idx, en_next = g[idx].next;

    int tmp[block_num], cnt = 0;
    for(int i = st_next; i != en_next; i = g[i].next)
    {
        g[i].rev ^= 1;
        tmp[++cnt] = i;
    }
    tmp[++cnt] = st, tmp[0] = en_next;
    for(int i = cnt; i >= 1; i--) g[tmp[i]].next = tmp[i-1];
    block_merge(head);
}
void block_print(int k)
{
    int idx = head;
    block_locate(idx, k);
    if(k == g[idx].sz) idx = g[idx].next, k = 0;//输出字符时特判一下，用下面的输出函数不用特判
    block_update(idx);
    printf("%c\n", g[idx].s[k]);
}
void block_print(int k, int n, char *str)
{
    int idx = head;
    block_locate(idx, k);
    int len = 0;
    for(int i = idx; i != -1 && n > 0; i = g[i].next)
    {
        block_update(i);
        int sz = min(n, g[i].sz - k);
        memcpy(str + len, g[i].s + k, sizeof(char) * sz);
        len += sz, n -= sz;
        k = 0;
    }
    str[len] = '\0';
    puts(str);
}
int main()
{
//    freopen("d://in.txt", "r", stdin);
//    freopen("d://out1.txt", "w", stdout);
    int T, i, j, n,cmd,pos;
    char text[100000],ch[2];
    ch[1] = '\0';
    cin >> T;
    for(i=0;i<T;i++){
        block_init();
        cin >> text;
        cout << text << endl;
        block_insert(0, strlen(text)+1, text);
        cin >> n;
        while(n--){
            cin >> cmd;
            if(cmd==1){
                // insert
                cin >> ch >> pos;
                block_insert(pos, 1, ch);
            }else{
                // lookup
                cin >> pos;
                block_print(pos);
            }
        }
    }
    int cur = 0;
    char op[20];
    
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", op);
        if(op[0] == 'M') scanf("%d", &cur);
        else if(op[0] == 'I')
        {
            int len;
            scanf("%d", &len);
            int i = 0;
            while(i < len) {char ch = getchar();if(ch >= 32 && ch <= 126) str[i++] = ch;}
            str[i++] = '\0';
            
        }
        else if(op[0] == 'D')
        {
            int len;
            scanf("%d", &len);
            block_delete(cur, cur + len);
        }
        else if(op[0] == 'R')
        {
            int len;
            scanf("%d", &len);
            block_rev(cur, cur + len);
        }
        else if(op[0] == 'G')
        {
            
            //block_print(cur, 1, str);
        }
        else if(op[0] == 'P') cur--;
        else if(op[0] == 'N') cur++;
    }
    return 0;
}