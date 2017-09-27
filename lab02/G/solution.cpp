#include <bits/stdc++.h>

using namespace std;
long S[10000];
int bin_search(int l, int r, long target, long scores[])
{
    // binary search here
    int idx = -1;
    long mid;
    while (l < r - 1)
    {
        mid = (l + r) / 2;
        //cout << l << mid << r << endl;
        if (target > scores[mid])
            l = mid;
        else if (target < scores[mid])
            r = mid;
        else
        {
            idx = mid + 1;
            break;
        }
    }
    if (target == scores[l])
        idx = l + 1;
    else if (target == scores[r])
        idx = r + 1;
    return idx;
}

int main()
{
    int T, N, i, Q;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> N;
        if (N == 0)
            continue;
        int j = 0;
        memset(S, 0, sizeof(S));
        for (j = 0; j < N; j++)
        {
            cin >> S[j];
        }
        long min = S[0], max = S[N - 1];
        long x;
        cin >> Q;
        if (Q == 0)
            continue;
        for (j = 0; j < Q; j++)
        {
            cin >> x;
            if (x < min || x > max)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << bin_search(0, N, x, S)<<endl;
            }
        }
    }
}