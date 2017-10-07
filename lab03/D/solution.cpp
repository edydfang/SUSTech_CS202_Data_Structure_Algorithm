#include <iostream>
#include <list>
#include <vector>

using namespace std;

/**
list<int>::iterator get_it(list<int> lst, int offset)
{
    int i;
    list<int>::iterator it = lst.begin();
    for (i = 0; i < offset; i++)
    {
        it++;
    }
    return it;
}
**/

int main()
{
    int T, i, j, n, k;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n >> k;
        list<int> soldier;
        list<int>::iterator it;
        int tmp = 0;
        for (tmp = 0; tmp < n; ++tmp)
        {
            soldier.push_back(tmp);
            //cout << tmp<< endl;
        }
        int leader = 0, offset;
        while (soldier.size() > 1)
        {
            offset = (leader + k) % soldier.size();
            //cout << "off " << offset << "leader " << leader << "size " << soldier.size() << endl;
            //leader = (offset + 1) % soldier.size();
            leader = offset;
            list<int>::iterator it = soldier.begin();
            advance(it, offset);
            //cout << "erase " << *it << endl;
            //soldier.erase(get_it(soldier, offset));
            soldier.erase(it);
        }
        /*
        for (int n : soldier) {
            std::cout << n << '\n';
        }
        */
        cout << soldier.front() << endl;
    }
    return 0;
}