#include <iostream>

using namespace std;
int stack[1000];
int main()
{
    int T, n, m, i, j, cmd, tmp, top = -1;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        top = -1;
        //cin >> n >> m;
        scanf("%d %d",&n, &m);
        for (j = 0; j < m; j++)
        {
            //cin >> cmd;
            scanf("%d",&cmd);
            if (cmd == 1)
            {
                scanf("%d",&tmp);
                //cin >> tmp;
                if (top == n-1)
                {
                    //cout << tmp << endl;
                    printf("%d\n",tmp);
                }
                else
                {
                    // push
                    stack[++top] = tmp;
                }
            }
            else if(top!=-1)
            {
                //cout << stack[top--] << endl;
                printf("%d\n",stack[top--]);
            }
        }
        for(j=top;j>-1;j--){
            //cout << stack[j] << endl;
            printf("%d\n",stack[j]);
        }
    }
    return 0;
}