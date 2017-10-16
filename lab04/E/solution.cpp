#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;
int T, n, tmp, i, j, k, count = 0, cur_max, max_idx;
int output[500000];
typedef struct node
{
    int idx;
    int value;
} Node;
int main()
{
    stack<Node> s;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        count = 0;
        cur_max = -1;
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d",&tmp);
            Node node_ = {j + 1, tmp};
            
            if (s.empty())
            {
                s.push(node_);
            }
            else
            {
                //cout << "s-top" << s.top().value << endl;
                if (tmp > s.top().value)
                {
                    do
                    {
                        output[s.top().idx - 1] = j + 1;
                        //cout << "output" << s.top().idx - 1<<"--"<< j+1 << endl;
                        s.pop();
                    } while (!s.empty() && tmp > s.top().value);
                }
                s.push(node_);
            }
        }
        while (!s.empty())
        {
            output[s.top().idx - 1] = 0;
            s.pop();
        }
        for (j = 0; j < n; j++)
        {
            printf("%d\n", output[j]);
        }
    }
    return 0;
}