#include <iostream>
#include <stdio.h>
#define MAXSIZE 100010
using namespace std;
int queue[MAXSIZE];
// flag = 0 normal -1 empty
int T, n, i, j, cmd[2], tmp, front = 0, rear = 0, next, flag = -1;
void push_first(int num)
{
    front = front - 1;
    if (front < 0)
        front += MAXSIZE;
    queue[front] = num;
}
void pop_first()
{
    //cout << queue[front] << endl;
    front = (front + 1) % MAXSIZE;
}
void push_last(int num)
{
    queue[rear] = num;
    rear = (rear + 1) % MAXSIZE;
}
void pop_last()
{
    //cout << queue[rear-1] << endl;
    rear = (rear - 1);
    if (rear < 0)
        rear += MAXSIZE;
}
int main()
{
    cin >> T;
    for (i = 0; i < T; i++)
    {
        flag = -1;
        front = 0;
        rear = 0;
        scanf("%d", &n);
        //cin >> n;
        for (j = 0; j < n; j++)
        {
            scanf("%d %d", &cmd[0], &cmd[1]);
            //cin >> cmd[0] >> cmd[1];
            if (cmd[0] == 1 && cmd[1] == 1)
            {
                scanf("%d", &tmp);
                //cin >> tmp;
                push_first(tmp);
            }
            else if (cmd[0] == 1 && cmd[1] == 2)
            {
                pop_first();
            }
            else if (cmd[0] == 2 && cmd[1] == 1)
            {
                scanf("%d", &tmp);
                //cin >> tmp;
                push_last(tmp);
            }
            else if (cmd[0] == 2 && cmd[1] == 2)
            {
                pop_last();
            }
            //cout << "front" <<front <<"rear"<< rear << endl;
        }
        if (front < rear)
        {
            j = front;
            while (j != rear)
            {
                printf("%d\n", queue[j++]);
            }
        }
        else
        {
            j = front;
            while (j != rear)
            {
                printf("%d\n", queue[j]);
                j = (j + 1) % MAXSIZE;
            }
        }
    }
    return 0;
}