#include <iostream>
#include <stdlib.h> 

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    int T, i, j, k, t, m, n;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> m >> n;
        long x[m], y[n];
        for (j = 0; j < m; j++)
        {
            cin >> x[j];
        }
        for (j = 0; j < n; j++)
        {
            cin >> y[j];
        }
        k = 0;
        t = 0;
        qsort (x, m, sizeof(long), compare);
        qsort (y, n, sizeof(long), compare);
        for (j = 0; j < m + n; j++)
        {
            if (k < m && x[k] < y[t])
            {
                cout << x[k];
                k++;
            }
            else if (t < n)
            {
                cout << y[t];
                t++;
            }
            //if (k + t < m + n)
                cout << " ";
        }
        //if (i != T - 1)
            cout << endl;
    }

    return 0;
}