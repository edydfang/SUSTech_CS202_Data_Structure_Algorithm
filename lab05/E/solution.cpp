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
    // for (vector<int>::const_iterator i = longestPrefix.begin(); i != longestPrefix.end(); ++i)
    // std::cout << *i << ' ';
    return longestPrefix;
}
long solve(string pat)
{
    long hash = 0;
    int m = pat.size();
    long count[m];
    vector<int> longestPrefix = computePrefix(pat);
    for (int i = 0; i < m; i++)
    {
        count[i] = 1;
    }
    for (int i = m - 1; i > -1; i--)
    {
        count[longestPrefix[i]-1] += count[i];
        hash += (long)(i + 1) * count[i];
        //cout << i+1 << "-" << count[i] << endl;
    }
    return hash;
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