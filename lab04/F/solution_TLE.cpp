#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
// Using Dequeue - Douoble-ended queue -- magic queue, time complexity: O(n)
// Time Limit Exceed, you should write a dequeue yourself

int T, n, k, i, j, tmp, arr[500010], minv[500000], maxv[500000];

int main()
{
    cin >> T;
    deque<int> S, G;
    for (i = 0; i < T; i++)
    {
        scanf("%d %d", &n, &k);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        // Create a Double Ended Queue, Qi that will store indexes of array elements
        // The queue will store indexes of useful elements in every window and it will
        // maintain decreasing order of values from front to rear in Qi, i.e.,
        // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
        /* Process first k (or first window) elements of array */
        for (j = 0; j < k; ++j)
        {
            // Remove all previous greater elements that are useless.
            while ((!S.empty()) && arr[S.back()] >= arr[j])
                S.pop_back(); // Remove from rear

            // Remove all previous smaller that are elements are useless.
            while ((!G.empty()) && arr[G.back()] <= arr[j])
                G.pop_back(); // Remove from rear

            // Add current element at rear of both deque
            G.push_back(j);
            S.push_back(j);
        }
        //cout << S.front() << "--" << G.front() << endl;
        minv[0] = S.front();
        maxv[0] = G.front();
        // Process rest of the elements, i.e., from arr[k] to arr[n-1]
        for (; j < n; ++j)
        {
            // Element at the front of the deque 'G' & 'S'i s the largest and smallest
            // element of previous window respectively

            // Remove all elements which are out of this window
            while (!S.empty() && S.front() <= j - k)
                S.pop_front();
            while (!G.empty() && G.front() <= j - k)
                G.pop_front();

            // remove all previous greater element that are useless
            while ((!S.empty()) && arr[S.back()] >= arr[j])
                S.pop_back(); // Remove from rear

            // remove all previous smaller that are elements are useless
            while ((!G.empty()) && arr[G.back()] <= arr[j])
                G.pop_back(); // Remove from rear

            // Add current element at rear of both deque
            G.push_back(j);
            S.push_back(j);
            minv[j - k + 1] = S.front();
            maxv[j - k + 1] = G.front();
            //cout << S.front() << "--" << G.front() << endl;
        }
        for (j = 0; j < n - k + 1; j++)
        {
            printf("%d ", arr[minv[j]]);
        }
        printf("\n");
        for (j = 0; j < n - k + 1; j++)
        {
            printf("%d ", arr[maxv[j]]);
        }
        printf("\n");
    }
    return 0;
}