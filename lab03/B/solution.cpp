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
            //cout << "gg" << iter->first <<endl;
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
        bool plus = false;
        for (map<int, long>::iterator iter = sumup.begin(); iter != sumup.end(); ++iter)
        {
            long coe = iter->second;
            if (iter->second != 0)
            {
                if (plus)
                {
                    if(coe>0){
                    cout << "+";
                }
                }
                else
                {
                     
                    plus = true;
                }
                if (coe!=1&&coe!=-1)
                {
                    cout << iter->second;
                }
                if(coe==-1 && iter->first !=0){
                    cout << "-";
                }
                if(coe==-1 && iter->first ==0){
                    cout << "-1";
                }
                if(coe==1 && iter->first ==0){
                    cout << "1";
                }
                if (iter->first == 1)
                {
                    cout << "x";
                }
                else if (iter->first != 0)
                {
                    cout << "x^" << iter->first;
                }
            }
        }
        if (!plus)
        {
            cout << "0";
        }
        cout << endl;
    }
    return 0;
}