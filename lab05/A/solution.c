#include <stdio.h>
#include <string.h>
 
char string[1010];
int T, strlength, i;
 
int main(){
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%s",&string);
        strlength = strlen(string);
        printf("%d\n", (1+strlength)*strlength/2);
    }
    return 0;
}