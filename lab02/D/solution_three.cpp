// auther: iamxieyi
#include <iostream>
using namespace std;

int main()
{
    int T, n, m, a[5001], head, tail, other, sum;
    bool has;
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        head = 1;
        tail = n - 1;
        has = false;
        // hold the center one (head), move the other two towards the center
        while (head < n - 1)
        {
            tail = n - 1;
            other = 0;
            while (head < tail && other < head)
            {
                while (a[head] + a[tail] + a[other] > m && head < tail)
                    tail--;
                while (a[head] + a[tail] + a[other] < m && other < head)
                    other++;
                if (a[head] + a[tail] + a[other] == m && other < head && head < tail)
                {
                    cout << "YES" << endl;
                    has = true;
                    break;
                }
            }
            if (has)
                break;
            head++;
        }
        if (!has)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}