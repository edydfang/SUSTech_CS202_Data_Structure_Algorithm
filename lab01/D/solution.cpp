#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string L, R;
ll res;
pair<string, string> p[5] = {{"0", "0"}, {"1", "1"}, {"6", "9"}, {"8", "8"}, {"9", "6"}};

void dfs(string tmp, int len)
{
    if (tmp.length() == len && tmp.length() >= L.length() && tmp.length() <= R.length())
    {
        if ((tmp.length() == L.length() && tmp < L) || (tmp.length() == R.length() && tmp > R))
            return;
        if (!(tmp.length() > 1 && tmp[0] == '0') && tmp.length() == len)
        {
            res++;
        }
    }

    if (tmp.length() + 2 > len)
        return;
    for (int i = 0; i < 5; i++)
        dfs(p[i].first + tmp + p[i].second, len);
}

int main()
{
    while (cin >> L >> R)
    {
        res = 0;
        for (int i = L.length(); i <= R.length(); i++)
        {
            dfs("", i);
            dfs("0", i);
            dfs("1", i);
            dfs("8", i);
        }
        cout << res << endl;
    }

    return 0;
}
