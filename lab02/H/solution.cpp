#include <bits/stdc++.h>

using namespace std;

int main(){
    int T,i;
    cin >> T;
    for(i=0;i<T;i++){
        int x,y,count = 0;
        cin >> x >> y;
        // impossible only when one cup has 2 times of water of the other does
        while(x!=y){
            if(x == 2*y || y == 2*x){
                count = -1;
                break;
            }
            if(x<y){
                y = y-x;
                x = 2*x;
            }else{
                x = x-y;
                y = 2* y;
            }
            count ++ ;
        }
        if(x==y){
            count ++;
        }
        cout << count << endl;
    }
    return 0;
}