#include <bits/stdc++.h>
using namespace std;

long get_power_mod(long base, long power, long mod, long data[])
{
    if (power == 0)
        return 1;
    else if (data[power] != -1)
        return data[power];
    else if (power == 1)
    {
        data[power] = base % mod;
        //cout << data[power] << endl;
        return data[power];
    }
    else
    {
        long tmp = get_power_mod(base, power / 2L, mod, data);
        long r = 1;
        if (power % 2)
        {
            r = get_power_mod(base, 1, mod, data);
        }
        tmp = (tmp * tmp * r) % mod;
        data[power] = tmp;
        return data[power];
    }
}

int main()
{
    int T, i, N, j;
    long K, X;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        // read in
        cin >> N >> K >> X;
        long a[N], powers[N];
        for (j = 0; j < N; j++)
        {
            cin >> a[j];
        }
        long n_circles = K / N;
        int remain = K % N;
        for (j = 0; j < N; j++)
        {
            powers[j] = n_circles;
            if (X + remain > N)
            {
                if (j >= X || j < ((X + remain) % N))
                {
                    powers[j]++;
                }
            }
            else
            {
                if ((j >= X && j < (X + remain)))
                {
                    powers[j]++;
                }
            }
        }
        // (x+y)^m % x = y^m when y < x
        // f_final = (a)^power*f mod 123456789
        for (j = 0; j < N; j++)
        {
            //cout << "pow" << powers[j] << endl;
            if (powers[j] > 0)
            {
                
                long p = powers[j];
                cout << " pwr  "<<long(log(p) / log(2)) + 1 << endl;
                long power_result[long(log(p) / log(2)) + 1];
                cout << " pwr gg" << endl;
                fill_n(power_result, p + 1, -1);
                //memset(power_result,-1L,sizeof(long)*powers[j]);

                long x = get_power_mod(a[j], p, 123456789L, power_result);
                cout << x;
            }
            else
            {
                cout << a[j] % 123456789L;
            }

            if (j < N - 1)
                cout << " ";
        }
        cout << endl;
    }
}