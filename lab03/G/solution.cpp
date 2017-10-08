#include <iostream>
#include <set>

using namespace std;

int move_median(set<int> sortedlst[], set<int>::iterator &cur_it, int cur_idx, int left_right)
{
    switch (left_right)
    {
    case 0: //left
        if (sortedlst[cur_idx].begin() != cur_it)
        {
            cur_it--;
            return cur_idx;
        }
        else
        {
            set<int>::iterator it = sortedlst[cur_idx - 1].end();
            cur_it = --it;
            return --cur_idx;
        }
        break;
    case 1: //right
        //cout << "s3" << endl;
        set<int>::iterator it = cur_it;
        if (++it == sortedlst[cur_idx].end())
        {
            //cout << "s0" << endl;
            cur_it = sortedlst[++cur_idx].begin();
            return cur_idx;
        }
        else
        {
            //cout << "s1" << endl;
            cur_it++;
            return cur_idx;
        }
        break;
    }
}

int main()
{
    int T, i, j, n;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        int tmp, bucket_idx, k, prev;
        set<int>::iterator median_it;
        set<int> sortedlst[100]; //10 buckets
        for (j = 0; j < n; j++)
        {
            cin >> tmp;
            bucket_idx = tmp / 100;
            sortedlst[bucket_idx].insert(tmp);
            if (j == 0)
            {
                k = bucket_idx;
                median_it = sortedlst[k].begin();
            }
            else if (j % 2 == 1)
            {
                prev = tmp;
            }
            else
            {
                //cout << "s2" << endl;
                //cout << "input " << tmp << "k " << k << "median " << *median_it << endl;
                if (prev < *median_it && tmp < *median_it)
                {
                    k = move_median(sortedlst, median_it, k, 0);
                }
                else if (prev > *median_it && tmp > *median_it)
                {
                    k = move_median(sortedlst, median_it, k, 1);
                }
            }
            if (j % 2 == 0)
            {
                cout << *median_it;
                if (j != n - 1 && j != n - 2)
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}