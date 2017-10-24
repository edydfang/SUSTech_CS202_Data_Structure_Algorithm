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
long solve(string str)
{
    long cycle = 0;
    int m = str.size();
    long count[m];
    vector<int> longestPrefix = computePrefix(str);
    cycle = m - longestPrefix[m-1];
    return cycle;
}
int T, i, tmp;
string str;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> tmp >> str;
        cout << solve(str) << endl;
    }
    return 0;
}