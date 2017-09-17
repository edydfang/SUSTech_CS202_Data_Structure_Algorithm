#include <bits/stdc++.h>
// reference http://www.programering.com/a/MTM5ETNwATE.html
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
            ropes[i] = input * 100.0;
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
        int res = 0;
        while (l <= r)
        {
            int mid = (r + l) / 2;
            //printf("l = %d, r = %d, mid = %d, res = %d.\n", l, r, mid, res);
            if (test_avaiable(ropes,mid))
                res = max(res, mid), l = mid + 1;
            else r = mid - 1;
        }
        cout << res/100 << "." << setfill('0') << setw(2) << res % 100 <<endl;
        
    }
    return 0;
}