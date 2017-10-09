#include <iostream>
#include <set>

// use the data structure red black tree

using namespace std;

int main()
{
    int T, i, j, n;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        int tmp;
        set<int> sortedlst;
        for (j = 0; j < n; j++)
        {
            cin >> tmp;
            sortedlst.insert(tmp);
            if (j % 2 == 0)
            {
                set<int>::iterator it = sortedlst.begin();
                std::advance(it, sortedlst.size() / 2);
                cout << *it;
                if (j != n - 1 && j != n - 2)
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}