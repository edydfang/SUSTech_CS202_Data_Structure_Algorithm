#include <iostream>
#include <map>

using namespace std;

// this version is a simple versin
// the multiplication can be implemented using FFT

int main()
{
    int i, j, T, m, n, coe;
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
        map<int, long> product;
        // start multiplication here
        for (map<int, long>::iterator itera = fst.begin(); itera != fst.end(); ++itera)
        {
            for (map<int, long>::iterator iterb = scd.begin(); iterb != scd.end(); ++iterb)
            {
                expo = itera->first + iterb->first;
                coe = itera->second * iterb->second;
                //cout << "coe " <<coe <<"expo "<<expo <<endl;
                if (product.count(expo) < 1)
                {
                    product[expo] = coe;
                }
                else
                {
                    product[expo] += coe;
                }
            }
        }
        bool plus = false;
        for (map<int, long>::iterator iter = product.begin(); iter != product.end(); ++iter)
        {
            long coe = iter->second;
            if (iter->second != 0)
            {
                if (plus)
                {
                    if (coe > 0)
                    {
                        cout << "+";
                    }
                }
                else
                {

                    plus = true;
                }
                if (coe != 1 && coe != -1)
                {
                    cout << iter->second;
                }
                if (coe == -1 && iter->first != 0)
                {
                    cout << "-";
                }
                if (coe == -1 && iter->first == 0)
                {
                    cout << "-1";
                }
                if (coe == 1 && iter->first == 0)
                {
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