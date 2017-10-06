#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

int main()
{
    int T, i, m, n, j, coe;
    long expo;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> m;
        map<int, long> fst;
        for (j = 0; j < m; j++)
        {
            cin >> coe >> expo;
            fst[expo] = coe;
        }
        cin >> n;
        map<int, long> scd;
        for (j = 0; j < n; j++)
        {
            cin >> coe >> expo;
            scd[expo] = coe;
        }
        map<int, long> sumup;
        for (map<int, long>::iterator iter = fst.begin(); iter != fst.end(); ++iter)
        {
            map<int, long>::iterator itscd = scd.find(iter->first);
            if (itscd != scd.end())
            {
                sumup[iter->first] = iter->second + itscd->second;
            }
            else
            {
                sumup[iter->first] = iter->second;
            }
        }
        for (map<int, long>::iterator iter = scd.begin(); iter != scd.end(); ++iter)
        {
            if (sumup.count(iter->first) == 0)
            {
                sumup[iter->first] = iter->second;
            }
        }
        for (map<int, long>::iterator iter = sumup.begin(); iter != sumup.end(); ++iter)
        {
            if (iter->second != 0)
            {
                if (iter->first != 0)
                {
                    cout << iter->second << "x^" << iter->first;
                }
                else
                {
                    cout << iter->second;
                }
            }
            if (iter != --sumup.end())
            {
                cout << "+";
            }
        }
        cout << endl;
    }
    return 0;
}