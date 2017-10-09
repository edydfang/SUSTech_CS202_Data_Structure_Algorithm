#include <iostream>
#include <set>

// an optimized solution 1 when moving the pointer of the median

using namespace std;

int main()
{
    int T, i, j, n;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        int tmp, prev;
        set<int> sortedlst;
        set<int>::iterator median_it;
        for (j = 0; j < n; j++)
        {
            cin >> tmp;
            sortedlst.insert(tmp);
            if (j == 0)
            {
                median_it = sortedlst.begin();
            }
            else if (j % 2 == 1)
            {
                prev = tmp;
            }
            if (j % 2 == 0)
            {
                if (*median_it > tmp && *median_it > prev)
                {
                    median_it--;
                }
                else if (*median_it < tmp && *median_it < prev)
                {
                    median_it++;
                }
                cout << *median_it;
                if (j != n - 1 && j != n - 2)
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}