#include <iostream>
#include <vector>

using namespace std;

vector<int> computePrefix(string pat)
{
    int m = pat.size();
    vector<int> longestPrefix(m);
    longestPrefix[0] = 0;
    for (int i = 1, k = 0; i < m; i++)
    {
        while (k > 0 && pat[k] != pat[i])
        {
            k = longestPrefix[k - 1];
        }
        if (pat[i] == pat[k])
        {
            longestPrefix[i] = ++k;
        }
        else
        {
            longestPrefix[i] = k;
        }
        //cout << i << "--" << longestPrefix[i] << "||";
    }
    return longestPrefix;
}
void solve(string str)
{
    long cycle = 0;
    int m = str.size();
    int count = 0, curr[m];
    vector<int> longestPrefix = computePrefix(str);
    int pre = longestPrefix[m - 1];
    while (pre > 0)
    {
        curr[count++] = pre;
        //cout << pre << "  pre" << endl;
        pre = longestPrefix[pre-1];
    }
    for (int n = count - 1; n > -1; n--)
    {
        //cout << "curr" << curr[n] << "\n";
        cout << str.substr(0, curr[n]) << endl;
    }
    cout << str << endl;
    cout << endl;
    return;
}
int T, i, tmp;
string str;
int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> tmp >> str;
        solve(str);
    }
    return 0;
}