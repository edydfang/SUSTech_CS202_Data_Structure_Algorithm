#include <stdio.h>
#include <string.h>

const int maxn = 100000+5;
 
int main(){
    char text[maxn];
    int Next[maxn],curr[maxn];
    int T;
    scanf("%d",&T);
    int falg = 0;
    while (T--){
        int len;
        scanf("%d",&len);
        scanf("%s",text);
        Next[0] = Next[1] = 0;
        int j = 0;
        for (int i=1; i<len; i++) {
            while (j && text[j]!=text[i]){
                j  = Next[j];
            } 
            if (text[j]==text[i]) j++;
            Next[i+1] = j;
        }
        int counter = 0;
        int pre = Next[len];
        while(pre>0) {
            //printf("pre %d\n", pre);
            curr[counter] = pre;
            counter++;
            pre = Next[pre];
        }
        int n = counter-1;
        while(n-->=0){
            //printf("curr %d\n", curr[n+1]);
            for(int i = 0; i < curr[n+1]; i++) {
                printf("%c", text[i]);
            }
            printf("\n");
        }
        printf("%s\n", text);
        printf("\n");
    }
    return 0;
}