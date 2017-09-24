#include <bits/stdc++.h>

using namespace std;

int main(){
    int total,i =0;
    long n,m,j;
    cin >> total;
    for(i=0;i<total;i++){
        cin >> n >> m;
        long numbers[n];
        memset(numbers,0,sizeof(numbers));
        for(j=0;j<n;j++){
            cin >> numbers[j];
        }
        // binary search here
        long l=0,r=n-1,mid;
        bool find = false;
        while(l<r-1){
            mid = (l+r)/2;
            //cout << l << r << mid << endl;
            if(m>numbers[mid])
                l = mid;
            else if (m<numbers[mid])
                r = mid;
            else{
                find = true;
                break;
            }
        }
        if(m == numbers[r] || m == numbers[l])
            find = true;
        if(find)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}