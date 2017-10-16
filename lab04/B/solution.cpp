#include <iostream>
#include <stdio.h>

using namespace std;
int queue[1000];
// flag = 0 normal 1 full -1 empty
int T, n, m, i, j, cmd, tmp, flag = -1, front = 0, rear = 0, next;
int main()
{
    cin >> T;
    for (i = 0; i < T; i++)
    {
        flag = -1;
        front = 0;
        rear = 0;
        //cin >> n >> m;
        scanf("%d %d", &n, &m);
        for (j = 0; j < m; j++)
        {
            //cin >> cmd;
            scanf("%d", &cmd);
            if (cmd == 1)
            {
                scanf("%d", &tmp);
                //cin >> tmp;
                if (flag == 1)
                {
                    //cout << tmp << endl;
                    printf("%d\n", tmp);
                }
                else
                {
                    if (flag == -1)
                    {
                        flag = 0;
                    }
                    // push
                    queue[rear++] = tmp;
                    rear = rear % n;
                    if (rear == front)
                    {
                        flag = 1;
                    }
                }
            }
            else if (flag != -1)
            {

                //cout << stack[top--] << endl;
                printf("%d\n", queue[front++]);
                front = front % n;
                if (front == rear)
                {
                    flag = -1;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        //printf("front:%d rear:%d\n",front, rear);
        if (front < rear)
        {
            for (j = front; j < rear; j++)
            {
                //cout << stack[j] << endl;
                printf("%d\n", queue[j]);
            }
        }
        else if (flag == 0)
        {
            j = front;
            while (j != rear)
            {
                printf("%d\n", queue[j]);
                j = (j + 1) % n;
            }
        }
        else if (flag == 1)
        {
            int k = front;
            for (j = 0; j < n; j++)
            {
                //cout << stack[j] << endl;
                printf("%d\n", queue[k]);
                k = (k + 1) % n;
            }
        }
    }
    return 0;
}