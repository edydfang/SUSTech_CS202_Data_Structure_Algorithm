#include <bits/stdc++.h>
#include <string.h>
#include <set>
#include <tuple>
// [imoportant] please append the parameter -std=c++11

using namespace std;

tuple <int,int> cup_iterate(int x,int y){
    if(x<y){
        y = y-x;
        x = 2*x;
    }else{
        x = x-y;
        y = 2* y;
    }
    return make_tuple(x,y);
}

int main(){
    int T,i;
    cin >> T;
    for(i=0;i<T;i++){
        int x,y,count = 0;
        cin >> x >> y;
        // impossible when a ring exist
        // method 1: x1,y1 for one step each time
        //      x2,y2 for two steps each time
        // method 2: iteration time exceeds log(m+n)
        int x_=x,y_=y;
        while(x!=y){
            tie(x,y) = cup_iterate(x,y);
            tie(x_,y_)= cup_iterate(x_,y_);
            tie(x_,y_)= cup_iterate(x_,y_);
            if(x==x_ && x!=y){
                count = -1;
                break;
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