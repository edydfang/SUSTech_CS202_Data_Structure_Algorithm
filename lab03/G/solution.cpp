#include <iostream>
#include <list>
// use only doublely linked list O(nlogn) for 1 quick sort and O(n) for iteration

using namespace std;

int main()
{
    int T, i, j, n;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        int int_tmp;
        list<int> linkedlist;
        list<int>::iterator node_seq[n], node_median, node_tmp;
        // input the data
        for (j = 0; j < n; j++)
        {
            cin >> int_tmp;
            linkedlist.push_back(int_tmp);
            node_tmp = linkedlist.end();
            node_tmp--;
            node_seq[j] = node_tmp;
            //cout << "input " << node_tmp->data << endl;
        }
        // ensure the n is an odd number
        if (n % 2 == 0)
        {
            n = n - 1;
            linkedlist.pop_back();
        }
        // sort all the data
        linkedlist.sort();
        // get median node
        node_median = linkedlist.begin();
        advance(node_median, n / 2);
        // tranvrse reversely
        list<int>::iterator removed[2];
        int move = 0, result[n], k = 0, odd = 1;
        result[k++] = *node_median;
        removed[0] = node_seq[n - 1];
        for (j = n - 2; j > -1; j--)
        {
            //cout << "size" << linkedlist.size()<< endl;
            if (odd)
            {
                removed[1] = node_seq[j];
                odd = 0;
            }
            else
            {
                odd = 1;
                // update median node
                move = 0;
                if (*removed[0] < *node_median && *removed[1] < *node_median)
                {
                    move = 1;
                }
                else if (*removed[0] > *node_median && *removed[1] > *node_median)
                {
                    move = -1;
                }
                else if (*removed[0] == *node_median)
                {
                    if (*removed[1] < *node_median)
                    {
                        move = 1;
                    }
                    else
                    {
                        move = -1;
                    }
                }
                else if (*removed[1] == *node_median)
                {
                    if (*removed[0] < *node_median)
                    {
                        move = 1;
                    }
                    else
                    {
                        move = -1;
                    }
                }
                //cout << "mid" << *node_median <<endl;
                if (move != 0)
                {
                    do
                    {
                        //cout<<"move" << move <<endl;
                        advance(node_median, move);
                    } while (node_median == removed[0] || node_median == removed[1]);
                }
                //cout << "mid" << *node_median <<endl;
                linkedlist.erase(removed[0]);
                linkedlist.erase(removed[1]);
                result[k++] = *node_median;
                removed[0] = node_seq[j];
            }
            //cout << "rm" << "--"<<*node_seq[j] << endl;
        }
        //cout << "size" << linkedlist.size()<< endl;
        for (j = k - 1; j > -1; j--)
        {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
