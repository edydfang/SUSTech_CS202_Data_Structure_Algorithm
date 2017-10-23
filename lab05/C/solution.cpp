#include <iostream>
#include <vector>

using namespace std;

vector<int> computePrefix(string pat){
    int m = pat.size();
    vector<int> longestPrefix(m);
    for(int i = 1, k = 0; i < m; i++){
        while(k > 0 && pat[k] != pat[i]){
            k = longestPrefix[k - 1];
        }
        if(pat[i] == pat[k]){
            longestPrefix[i] = ++k;
        }
        else{
            longestPrefix[i] = k;
        }
    }
    return longestPrefix;
}
int KMP(string str,string pat){
    int count = 0;
    int n = str.size();
    int m = pat.size();
    vector<int> longestPrefix = computePrefix(pat);
    for(int i = 0, k = 0; i < n; i++){
        while(k > 0 && pat[k] != str[i]){
            k = longestPrefix[k - 1];
        }
        if(str[i] == pat[k]){
            k++;
        }
        if(k == m){
            count ++ ;
            //cout << i - m + 1 << "\n";
            k = longestPrefix[k - 1];
        }
    }
    return count;
}
int T,i,tmp;
string str,pattern;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(i=0;i<T;i++){
        cin >> tmp >> str >> tmp>>pattern;
        cout << KMP(str, pattern) << endl;
    }
    return 0;
}