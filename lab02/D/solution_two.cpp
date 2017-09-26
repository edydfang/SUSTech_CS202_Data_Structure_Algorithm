#include <bits/stdc++.h>

using namespace std;
long a[5001];

int binary_search(int l, int r, long target)
{
    int mid;

    // binary search
    while (l < r - 1)
    {
        mid = (l + r) / 2;
        //cout << numbers[k] << "--" << l << mid << r << endl;
        if (a[mid] < target)
        {
            l = mid;
        }
        else if (a[mid] > target)
        {
            r = mid;
        }
        else
        {
            return mid;
        }
    }

    // judge the edge conditioins 1.l==r 2.r==r+1
    if ((l >= r - 1))
    {
        if (a[l] == target)
        {
            return l;
        }
        else if (a[r] == target)
        {
            return r;
        }
    }

    return -1;
}

int main()
{
    int T, i, n;
    long m;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n >> m;
        int j, k, upper = -1;
        // input data
        for (j = 0; j < n; j++)
        {
            cin >> a[j];
            if (upper == -1 && a[j] >= m)
            {
                upper = j;
            }
        }
        if (upper == -1)
            upper = n;
        bool find = false;
        for (j = 0; j < upper; j++)
        {
            long r1 = m - a[j];
            if (r1 < a[j + 1])
            {
                break;
            }
            for (k = j + 1; k < upper; k++)
            {
                long r2 = r1 - a[k];
                if (r2 < a[k + 1])
                {
                    break;
                }
                int tmp = binary_search(k + 1, upper - 1, r2);
                if (tmp != -1)
                    find = true;
                if (find)
                    break;
            }
            if (find)
            {
                break;
            }
        }
        if (find)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
