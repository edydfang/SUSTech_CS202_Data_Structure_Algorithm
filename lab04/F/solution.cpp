// Shashank Jain
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
//#include <algorithm>

#define LIM 500010
// maybe too much memory
/* reference: https://stackoverflow.com/questions/8031939/finding-maximum-for-every-window-of-size-k-in-an-array
proof: (by @johnchen902)

If k % w != 1 (k is not the begin of a block)
Let k* = The begin of block index contained in index k's block
k, k+1, ..., k*-1 | k*, ..., k+w-1
ans[k] = max( arr[k], arr[k+1], arr[k+2], ..., arr[k+w-1])
       = max( max( arr[k],  arr[k+1],  arr[k+2],  ..., arr[k*]), 
              max( arr[k*], arr[k*+1], arr[k*+2], ..., arr[k+w-1]) )
       = max( RL[k], LR[k+w-1] )

Otherwise (k is the begin index of a block)
ans[k] = max( arr[k], arr[k + 1], arr[k + 2], ..., arr[k + w - 1])
       = RL[k] = LR[k+w-1]
       = max( RL[k], LR[k+w-1] )
*/
using namespace std;

int arr[LIM];          // Input Array
int LR[LIM], LR2[LIM]; // maximum from Left to Right
int RL[LIM], RL2[LIM]; // maximum from Right to left
int max_val[LIM];
// number of subarrays(windows) will be n-k+1
int n, w, i, k, T, j, min_val; // 'n' is number of elements in array
// 'w' is Window's Size
// 'K' is number of Windows
int main()
{
    cin >> T;
    for (i = 0; i < T; i++)
    {
        scanf("%d %d", &n, &w);
        //cin >> n >> w;
        k = n - w + 1;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        // requiring editing
        for (j = 0; j < n; j++)
        { // for maxjmum Left to Rjght
            if (j % w == 0)
            { // that means START of a block
                LR[j] = arr[j];
                LR2[j] = arr[j];
            }
            else
            {
                LR[j] = max(LR[j - 1], arr[j]);
                LR2[j] = min(LR2[j - 1], arr[j]);
            }
        }

        for (j = n - 1; j > -1; j--)
        { // for maxjmum Rjght to Left
            if (j == n)
            { // Maybe the last block js not of sjze 'W'.
                RL[j] = arr[j];
                RL2[j] = arr[j];
            }
            else if (j % w == w - 1)
            { // that means END of a block
                RL[j] = arr[j];
                RL2[j] = arr[j];
            }
            else
            {
                RL[j] = max(RL[j + 1], arr[j]);
                RL2[j] = min(RL2[j + 1], arr[j]);
            }
        }

        for (j = 0; j < k; j++)
        { // maxjmum
            max_val[j] = max(RL[j], LR[j + w - 1]);
            min_val = min(RL2[j], LR2[j + w - 1]);
            printf("%d ", min_val);
        }
        printf("\n");
        for (j = 0; j < k; j++)
        {
            printf("%d ", max_val[j]);
        }
        printf("\n");
    }

    return 0;
}