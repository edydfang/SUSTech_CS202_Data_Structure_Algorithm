#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int T, i, j, n, m, k, l, r, mid, max_k_val, queue_idx, idx;
int a[300000], sorted[300000];
bool block[300000];
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int find_maxlen(int max_k)
{
    int count = 0, tail = 0, maxlen = 0, head;
    // k-1 smaller than kth_val; +1
    while (tail < n && count < k - 1)
    {
        if (a[tail + 1] < max_k)
            count++;
        tail++;
    }
    if (count < k - 1)
        return m;
    while (tail < n && a[tail + 1] >= max_k)
    {
        tail++;
    }
    for (head = 1; head <= n - k + 1; ++head)
    {
        if (tail - head + 1 >= m && count == k - 1)
        {
            maxlen = max(maxlen, tail - head + 1);
        }
        if (a[head] < max_k)
            count--;
        while (tail < n && count < k - 1)
        {
            if (a[tail + 1] < max_k)
                count++;
            tail++;
        }
        if (count < k - 1)
            return maxlen;
        while (tail < n && a[tail + 1] >= max_k)
        {
            tail++;
        }
    }
    return maxlen;
}

/*
void find_maxlen2(int max_k, int last_idx)
{
    maxlen = m;
    int head = 0;
    for (j = last_idx + 1; j < n; j++)
    {
        if (a[j] > max_k)
        {
            maxlen++;
        }
        else
        {
            if (a[last_idx - m + 1 + head] < max_k)
            {
                head++;
            }
            else
            {
                break;
            }
        }
    }
    //cout << "start"<<a[last_idx - m + 1 + head] << "end"<<a[j-1]<<endl;
}
*/

// check whether the k_val is larger than the actual value or not
int test(int k_val)
{
    //cout << "max_k--val" <<  k_val <<endl;
    // the number of ai that is equal to or greater than k_val
    int count = 0;
    // return the index of stisfied block or -1
    for (j = 0; j < m; j++)
    {
        if (a[j] >= k_val)
        {
            count++;
            block[j] = true;
        }
        else
        {
            block[j] = false;
        }
    }
    if (count > m - k)
    {
        return j - 1;
    }
    queue_idx = 0;
    for (; j < n; j++)
    {
        if (block[queue_idx])
        { // true
            if (a[j] < k_val)
            { // false
                count--;
                block[queue_idx] = false;
            }
        }
        else
        { // false
            if (a[j] >= k_val)
            { // true
                count++;
                block[queue_idx] = true;
            }
        }
        queue_idx = (queue_idx + 1) % m;
        //cout << "max_k--count" <<  count <<endl;
        if (count > m - k)
        {
            return j;
        }
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
        qsort(sorted, n, sizeof(int), compare);
        l = 0;
        r = n - 1;
        while (l < r - 1)
        {
            mid = (l + r) / 2;
            idx = test(sorted[mid]);
            //cout << "idx" << idx << "mid" << sorted[mid] << endl;
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
        if (idx > -1)
        {
            max_k_val = sorted[r];
        }
        else
        {
            idx = test(sorted[l]);
            max_k_val = sorted[l];
        }
        //cout << idx  << "-"  << max_k_val << endl;
        //find_maxlen(max_k_val, idx);
        int maxlen = find_maxlen(max_k_val);
        printf("%d\n", maxlen);
    }
    return 0;
}
