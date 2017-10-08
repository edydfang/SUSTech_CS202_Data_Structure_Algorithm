#include <iostream>
#include <set>

using namespace std;

int main()
{
    int T, i, j, n;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        int tmp, bucket_idx, median_idx, k, prev_sum;
        set<int> sortedlst[100]; //10 buckets
        for (j = 0; j < n; j++)
        {
            cin >> tmp;
            bucket_idx = tmp / 100;
            sortedlst[bucket_idx].insert(tmp);
            if (j % 2 == 0)
            {
                median_idx = j / 2;
                for (k = 0; k < 100; k++)
                {

                    if (prev_sum + sortedlst[k].size() - 1 >= median_idx)
                    {
                        break;
                    }
                    prev_sum += sortedlst[k].size();
                }
                //cout << "sum " << prev_sum << "k " << k << endl;
                set<int>::iterator it = sortedlst[k].begin();
                std::advance(it, median_idx - prev_sum);
                cout << *it;
                if (j != n - 1 && j != n - 2)
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}