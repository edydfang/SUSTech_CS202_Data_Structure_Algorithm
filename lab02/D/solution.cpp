#include <bits/stdc++.h>

using namespace std;
int a[5001], sum[5001][5001]; // long -> cause segmentfault on OJ
int main()
{
    int T, i, n;
    long m;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n >> m;
        int j, k, upper = -1;
        memset(a, 0, sizeof(long) * n);
        memset(sum, 0, sizeof(long) * n * n);
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
        // preprocessing
        for (j = 0; j < n; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                sum[j][k] = a[j] + a[k];
            }
        }
        // binarysearch
        bool find = false;
        int l, r, mid;
        for (j = 0; j < upper; j++)
        {
            // find two sum for a[j] from sum[j+1][j+2] to sum[upper-1][upper-1]
            // method one: sort + binary search
            // method two: loop + binary search
            for (k = j + 1; k < upper; k++)
            {
                l = k;
                r = upper - 1;
                while (l < r - 1)
                {
                    mid = (l + r) / 2;
                    //cout << numbers[k] << "--" << l << mid << r << endl;
                    if (sum[k][mid] + a[j] < m)
                    {
                        l = mid;
                    }
                    else if (sum[k][mid] + a[j] > m)
                    {
                        r = mid;
                    }
                    else
                    {
                        //cout <<"1-"<< j << k << mid<<endl;
                        find = true;
                        break;
                    }
                }
                // judge the edge conditioins 1.l==r 2.r==r+1
                if ((l >= r - 1) && (sum[k][l] + a[j] == m || sum[k][r] + a[j] == m))
                {
                    //cout <<"2-"<< j << l << r <<endl;
                    find = true;
                }
                if (find)
                    break;
            }
            if (find)
                break;
        }
        if (find)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
