#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int T, i, j, n, m, k, l, r, mid, max_k_val, maxlen, queue_idx, idx;
int a[300000], sorted[300000];
bool block[300000];
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

// check whether the k_val is larger than the actual value or not
int test(int k_val)
{
    int count = 0;
    // return the index of stisfied block or -1
    for (j = 0; j < m; j++)
    {
        if (a[j] > k_val)
        {
            block[j] = true;
        }
        else
        {
            block[j] = false;
            count++;
        }
    }
    if (count >= k)
    {
        return j;
    }
    queue_idx = 0;
    for (; j < n; j++)
    {
        if (block[queue_idx])
        { // 1
            if (a[j] <= k_val)
            { // 0
                count++;
                block[queue_idx] = false;
            }
        }
        else
        { // 0
            if (a[j] > k_val)
            { // 1
                count--;
                block[queue_idx] = true;
            }
        }
        if (count >= k)
        {
            return j;
        }
        queue_idx = (queue_idx + 1) % m;
    }
    return -1;
}

int main()
{
    cin >> T;
    for (i = 0; i < T; i++)
    {
        scanf("%d %d %d", &n, &m, &k);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        memcpy(sorted, a, sizeof(int) * n);
        qsort(sorted,n,sizeof(int),compare);
        l = 0;
        r = n;
        while (l < r - 1)
        {
            mid = (l + r) / 2;
            idx = test(sorted[mid]);
            cout << "idx" << idx << "mid" << mid << endl;
            if (idx > -1)
            {
                l = mid;
            }
            else
            {
                r = --mid;
            }
        }
        idx = test(sorted[r]);
        cout << idx << endl;
        if (idx > -1)
        {
            max_k_val = sorted[r];
        }
        else
        {
            max_k_val = sorted[l];
        }
        cout << max_k_val << endl;
    }
    return 0;
}