#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int T, n, m, i, j, cmd, tmp;
    cin >> T;
    stack<int> stack_;
    for (i = 0; i < T; i++)
    {
        cin >> n >> m;
        for (j = 0; j < m; j++)
        {
            cin >> cmd;
            if (cmd == 1)
            {
                cin >> tmp;
                if (stack_.size() == n)
                {
                    cout << tmp << endl;
                }
                else
                {
                    stack_.push(tmp);
                }
            }
            else
            {
                if (!stack_.empty())
                {
                    cout << stack_.top() << endl;
                    stack_.pop();
                }
            }
        }
        while (!stack_.empty())
        {
            cout << stack_.top() << endl;
            stack_.pop();
        }
    }
    return 0;
}