#include <iostream>

using namespace std;

int main()
{
    int T, i, j, n,cmd,pos;
    string new_char;
    cin >> T;
    for(i=0;i<T;i++){
        string text;
        cin >> text;
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