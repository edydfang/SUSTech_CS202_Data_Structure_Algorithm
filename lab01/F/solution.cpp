#include <bits/stdc++.h>

using namespace std;

int n_ropes,n_piecces;

bool test_avaiable(double ropes[], double cur_len){
    int ava = 0;
    for(int i=0;i<n_ropes;i++){
        ava += (int) (floor(ropes[i]/cur_len));
        //cout<<(int) (ropes[i]/cur_len)<<endl;
    }
    if(ava<n_piecces){
        return false;
    }else{
        return true;
    }
}


int main(){
    while(cin >> n_ropes >> n_piecces){
        double ropes[n_ropes];
        double l=0,mid,r=0,diff=0;
        for(int i=0;i<n_ropes;i++){
            cin >> ropes[i];
            r += ropes[i];
        }
        mid = (l+r)/n_piecces;
        r = mid;
        do{
            
            if(test_avaiable(ropes,mid)){
                diff = r-mid;
                l = mid;
                mid = (l+r)/2;
            } else{
                diff = mid-l;
                r = mid;
                mid = (l+r)/2;
            }
        }while(diff>0.0001);
        cout << fixed << std::setprecision(2) << floor(r * 100) / 100 <<endl;
        
    }
    return 0;
}