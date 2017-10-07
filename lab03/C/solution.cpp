#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int T, i, j, n, m;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        list<int> combat;
        int tmp, cmd, p, x;
        for (j = 0; j < n; j++)
        {
            cin >> tmp;
            combat.push_back(tmp);
        }
        cin >> m;
        for (j = 0; j < m; j++)
        {
            cin >> cmd;
            //cout << cmd << endl;
            list<int>::iterator it = combat.begin();
            switch (cmd)
            {
            case 1:
                cin >> p >> x;
                for (tmp = 0; tmp < p; tmp++)
                {
                    it++;
                }
                combat.insert(it, x);
                break;
            case 2:
                cin >> p;
                for (tmp = 0; tmp < p; tmp++)
                {
                    it++;
                }
                combat.erase(it);
                break;
            case 3:
                cin >> p >> x;
                // erase and add
                for (tmp = 0; tmp < p; tmp++)
                {
                    it++;
                }
                combat.erase(it++);
                combat.insert(it, x);
                break;
            case 4:
                combat.reverse();
                break;
            }
            for (auto v : combat)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    return 0;
}