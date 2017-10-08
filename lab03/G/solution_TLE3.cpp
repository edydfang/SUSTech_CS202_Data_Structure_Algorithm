#include <iostream>
#include <set>

using namespace std;

int move_median(set<int> sortedlst[], set<int>::iterator &cur_it, int cur_idx, int left_right)
{
    switch (left_right)
    {
    case 0: //left
        //cout << "left" << endl;
        if (sortedlst[cur_idx].begin() != cur_it)
        {
            cur_it--;
            return cur_idx;
        }
        else
        {
            cur_idx--;
            while(sortedlst[cur_idx].size()==0){
                cur_idx--;
            }
            set<int>::iterator it = sortedlst[cur_idx].end();
            cur_it = --it;
            return cur_idx;
        }
        break;
    case 1: //right
        cur_it++;
        if (cur_it == sortedlst[cur_idx].end())
        {
            cur_idx++;
            while(sortedlst[cur_idx].size()==0){
                cur_idx++;
            }
            cur_it = sortedlst[cur_idx].begin();
            return cur_idx;
        }
        else
        {
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
        set<int> sortedlst[11]; //11 buckets
        for (j = 0; j < n; j++)
        {
            cin >> tmp;
            bucket_idx = tmp/1000;
            sortedlst[bucket_idx].insert(tmp);
            if (j == 0)
            {
                k = bucket_idx;
                median_it = sortedlst[k].begin();
                //cout << *median_it;
                printf("%d", *median_it);
                if (j != n - 1 && j != n - 2)
                //cout << " ";
                printf(" ");
            }
            else if (j % 2 == 1)
            {
                prev = tmp;
            }
            else
            {
                //cout << "input " << tmp << "k " << k << "median " << *median_it << endl;
                if (prev < *median_it && tmp < *median_it)
                {
                    k = move_median(sortedlst, median_it, k, 0);
                }
                else if (prev > *median_it && tmp > *median_it)
                {
                    k = move_median(sortedlst, median_it, k, 1);
                }
                printf("%d", *median_it);
                if (j != n - 1 && j != n - 2)
                printf(" ");
            }
        }
        cout << endl;
    }
    
    return 0;
}