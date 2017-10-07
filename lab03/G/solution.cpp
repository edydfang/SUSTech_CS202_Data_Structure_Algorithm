#include <iostream>
#include <list>

using namespace std;

class node
{
public:
    int value;
    int index;
}
int cmp_node (const void * a, const void * b)
{
  return (node *)a->value - (node *)b->value;
  //return ((node *)a)->value - ((node *)b)->value ;
}
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