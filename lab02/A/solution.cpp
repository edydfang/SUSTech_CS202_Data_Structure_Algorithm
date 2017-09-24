#include <bits/stdc++.h>

using namespace std;

int main(){
    int total,i =0;
    long long T;
    cin >> total;
    for(i=0;i<total;i++){
        cin >> T;
        long long result = T*(T+1)*(2*T+1)/6;
        cout << result << endl;
    }
}