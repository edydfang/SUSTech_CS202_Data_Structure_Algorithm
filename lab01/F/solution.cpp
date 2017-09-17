#include <bits/stdc++.h>

using namespace std;

int n_ropes,n_piecces;

bool test_avaiable(int ropes[], int cur_len){
    if(cur_len == 0)
        return true;
    int ava = 0;
    for(int i=0;i<n_ropes;i++){
        ava += ropes[i]/cur_len;
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
        int ropes[n_ropes];
        int l=0,mid,r=0,diff=0;
        double input;
        for(int i=0;i<n_ropes;i++){
            cin >> input;
            ropes[i] = floor(input * 100+0.5);
            r += ropes[i];
        }
        mid = (l+r)/n_piecces+1;
        r = mid;
        /* test
        cout << n_ropes << " " << n_piecces << endl;
		
		for (int i = 0; i < n_ropes; i++){
			cout << (int)(ropes[i]/100)<<"."<<setfill('0') << setw(2) <<ropes[i]%100 << " "; 
		}
        test*/
        int out;
        do{
            
            if(test_avaiable(ropes,mid)){
                diff = r-mid;
                out = mid;
                l = mid;
                mid = (l+r)/2;
            } else{
                diff = mid-l;
                out = l;
                r = mid;
                mid = (l+r)/2;
            }
        }while(diff>1);
        if(test_avaiable(ropes,out+1)){
            out = out+1;
        }else if(!test_avaiable(ropes,out)){
            out = out-1;
            cout<<"minus"<<endl;
        }
        cout << (int) (out/100) << "." << setfill('0') << setw(2) << out % 100 <<endl;
        
    }
    return 0;
}