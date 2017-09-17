#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getSum(char *num1, char *num2);
int main()
{
    char str1[1001], str2[1001];
    int i = 0, k = 0;
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            str2[i] = 0;
            //printf("%s\t%s\n",str1,str2);
            getSum(str1, str2);
            i = 0;
            k = (k + 1) % 2;
        }
        else if (ch == ' ')
        {
            str1[i] = 0;
            k = (k + 1) % 2;
            i = 0;
        }
        else
        {
            if (!k)
            {
                str1[i++] = ch;
            }
            else
            {
                str2[i++] = ch;
            }
        }
    }
    return 0;
}

void getSum(char *num1, char *num2)
{
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int maxlen = (l1 > l2 ? l1 : l2) + 1;
    int i = 0, carry = 0;
    int result[1002];

    while (i < l1 && i < l2)
    {
        result[i] = num1[l1 - i - 1] + num2[l2 - i - 1] - 2 * '0' + carry;
        if (result[i] > 9)
        {
            result[i] -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        i++;
    }
    while (i < l1)
    {
        result[i] = num1[l1 - i - 1] - '0' + carry;
        if (result[i] > 9)
        {
            result[i] -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        i++;
    }
    while (i < l2)
    {
        result[i] = num2[l2 - i - 1] - '0' + carry;
        if (result[i] > 9)
        {
            result[i] -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        i++;
    }
    if (!carry)
    {
        maxlen--;
    }
    else
    {
        result[i] = 1;
    }
    for (i = maxlen - 1; i > -1; i--)
    {
        printf("%d", result[i]);
    }
    printf("\n");
    return;
}