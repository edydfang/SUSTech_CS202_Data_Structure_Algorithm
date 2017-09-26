#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, i = 0, n, j;
    long m;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        int count = 0, upper = -1;
        cin >> n >> m;
        long numbers[n];
        memset(numbers, 0, sizeof(numbers));
        for (j = 0; j < n; j++)
        {
            cin >> numbers[j];
            //cout << "xxx: " << numbers[j] << endl;
            if (upper == -1 && numbers[j] > m)
            {
                upper = j;
            }
        }
        int l, r, mid, k = 0;
        if (upper == -1)
            upper = j;
        for (k = 0; k <= upper; k++)
        {
            l = k + 1;
            r = upper;
            if (l > r)
                break;
            // binary search
            while (l < r - 1)
            {
                mid = (l + r) / 2;
                //cout << numbers[k] << "--" << l << mid << r << endl;
                if (numbers[mid] + numbers[k] < m)
                {
                    l = mid;
                }
                else if (numbers[mid] + numbers[k] > m)
                {
                    r = mid;
                }
                else
                {
                    count++;
                    break;
                }
            }

            // judge the edge conditioins 1.l==r 2.r==r+1
            if ((l >= r - 1) && (numbers[r] + numbers[k] == m || numbers[l] + numbers[k] == m))
            {
                count++;
            }
        }

        cout << count << endl;
    }
}