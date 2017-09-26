#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, i = 0, n, j;
    long m;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        int count = 0;
        cin >> n >> m;
        long numbers[n], needs[n];
        memset(numbers, 0, sizeof(numbers));
        for (j = 0; j < n; j++)
        {
            cin >> numbers[j];
            if (numbers[j] > m)
            {
                break;
            }
            else
            {
                needs[j] = m - numbers[j];
            }
        }
        int l, r, mid, k = 0, upper_bound = j;
        for (k = 0; k <= j; k++)
        {
            l = 0;
            r = upper_bound;
            // binary search needs[j] and update lower bound
            while (l < r - 1)
            {
                mid = (l + r) / 2;
                cout << l << "-" << r << "-" << mid << endl;
                if (numbers[mid] < needs[k])
                {
                    l = mid;
                }
                else if (numbers[mid] > needs[k])
                {
                    r = mid;
                    upper_bound = r;
                }
                else
                {
                    cout<<"ok" << numbers[mid] << endl;
                    (k - mid)*(m-needs[k]-numbers[mid])
                    count++;
                    break;
                }
            }
            if ((l < r - 1) && (numbers[l] == needs[k] || numbers[r] == needs[k]))
            {
                count++;
            }
        }

        cout << count <<endl;
    }
}