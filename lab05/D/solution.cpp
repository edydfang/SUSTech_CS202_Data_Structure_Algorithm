#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int T, i, tmp;
string str, pattern;

vector<int> computePrefix(string pat)
{
    int m = pat.size();
    ///int *longestPrefix = (int *)malloc(sizeof(int)*m);
    vector<int> longestPrefix(m);
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
    }
    return longestPrefix;
}
int KMP(string &str, string pat)
{
    int count = 0;
    int n = str.size();
    int m = pat.size();
    vector<int> longestPrefix = computePrefix(pat);
    //int * longestPrefix = computePrefix(pat);
    for (int i = 0, k = 0; i < n; i++)
    {
        //cout << "i " << i << " k " << k << endl;
        while (k > 0 && pat[k] != str[i])
        {
            k = longestPrefix[k - 1];
        }
        if (str[i] == pat[k])
        {
            k++;
        }
        if (k == m)
        {
            count++;
            str.erase(i - m + 1, m);
            //cout << i - m + 2<< "gg"<< m << endl;
            if (i - 2 * m + 2 > -2)
            {
                i = i - 2 * m + 2;
            }
            else
            {
                i = -1;
            }
            k = 0;
            
            //k = longestPrefix[k - 1];
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> tmp >> str;
        cin >> tmp >> pattern;
        KMP(str, pattern);
        //cout << KMP(str, pattern) << endl;
        cout << str << endl;
    }
    return 0;
}