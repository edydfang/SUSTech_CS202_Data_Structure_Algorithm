#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int T, n, i, j, in1, in2;
string s, cmd, sub;
char ch;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> s >> n;
        for (j = 0; j < n; j++)
        {
            cin >> cmd;
            if (cmd[0] == 'S')
            {
                cin >> in1 >> in2;
                sub = s.substr(in1, in2 - in1 + 1);
                cout << sub << endl;
            }
            else if (cmd[0] == 'D')
            {
                cin >> in1;
                s.erase(in1, 1);
                cout << s << endl;
            }
            else if (cmd[0] == 'R')
            {
                cin >> in1 >> in2;
                reverse(s.begin() + in1, s.begin() + in2 + 1);
                cout << s << endl;
            }
            else if (cmd[0] == 'A')
            {
                cin >> ch >> in1;
                s.insert(in1, 1, ch);
                cout << s << endl;
            }
        }
    }
}