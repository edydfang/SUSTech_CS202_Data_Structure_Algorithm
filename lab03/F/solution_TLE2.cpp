#include <bits/stdc++.h>
#include <ext/rope>


using namespace std;
using namespace __gnu_cxx;

int main()
{
    int T, i, j, n,cmd,pos;
    char new_char, inittext[100000];
    cin >> T;
    for(i=0;i<T;i++){
        crope text;
        cin >> inittext;
        text.insert(0,inittext);
        cin >> n;
        for(j=0;j<n;j++){
            cin >> cmd;
            switch(cmd){
                case 1:
                    cin >> new_char >> pos;
                    text.insert(pos-1,new_char);
                    break;
                case 2:
                    cin >> pos;
                    cout << text[pos-1] << endl;
                    break;
            }
        }
        
    }
    return 0;
}