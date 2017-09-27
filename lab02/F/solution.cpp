#include <bits/stdc++.h>
using namespace std;

bool is_feasible(long seat[],int n,long dist,int k){
    int taken = 1,i;
    long last_pos = seat[0];
    for(i = 1;i<n;i++){
        if(seat[i]-last_pos>=dist){
            taken ++;
            last_pos = seat[i];
        }
    }
    //cout << "debug" << dist << (taken>=k) << endl;
    return taken>=k;
}


int main(){
    int T,N,K,i,j;
    cin >> T;
    for(i=0;i<T;i++){
        cin >> N >> K;
        //cout << "debug " << N<<"-"<<K << endl;
        long seat[N];
        memset(seat,0,sizeof(seat));
        // readin
        for(j=0;j<N;j++){
            cin>>seat[j];
        }
        // bound of the max min distance
        long l = 0,r = seat[N-1] - seat[0], mid;
        while(l<r-1){
            mid = (l+r)/2;
            if(is_feasible(seat,N,mid,K)){
                l = mid;
            }else{
                r = mid;
            }
        }
        // edge condition
        if(is_feasible(seat,N,r,K)){
            cout<< r << endl;
        }else{
            cout << l << endl;
        }
    }
    return 0;
}