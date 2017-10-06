#include <iostream>

using namespace std;

int main(){
    int T,i,m,n,j,coe;
    long expo;
    cin >> T;
    for(i=0;i<T;i++){
        cin >> m;
        map<int,long> first;
        for(j=0;j<m;j++){
            cin>>coe>>expo;
            first[expo] = coe;
        }
        cin >> n;
        map<int,long> second;
        for(j=0;j<n;j++){
            cin>>coe>>expo;
            second[expo] = coe;
        }
        map<int,long> sumup;
        //for(map<int,long>::iterator iter = first.begin();)
    }
    return 0;
}