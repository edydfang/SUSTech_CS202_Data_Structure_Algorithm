#include <iostream>
#include <queue>

// use two data structure heaps

using namespace std;

int main()
{
    int T, i, j, n;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        int tmp, median;
        priority_queue<int> small_part;
        priority_queue<int, vector<int>, greater<int>> large_part;
        for (j = 0; j < n; j++)
        {
            cin >> tmp;

            if (j == 0)
            {
                small_part.push(tmp);
                median = tmp;
            }
            else if (j == 1)
            {
                if (tmp > small_part.top())
                {
                    large_part.push(tmp);
                }
                else
                {
                    large_part.push(small_part.top());
                    small_part.pop();
                    small_part.push(tmp);
                }
            }
            else
            {
                if(small_part.size() < large_part.size()){
                    if(tmp > small_part.top() && tmp < large_part.top()){
                        small_part.push(tmp);
                    }else if(tmp > large_part.top()){
                        small_part.push(large_part.top());
                        large_part.pop();
                        large_part.push(tmp);
                    }else{
                        small_part.push(tmp);
                    }
                    median = large_part.top();
                }else{
                    if(tmp > small_part.top() && tmp < large_part.top()){
                        large_part.push(tmp);
                    }else if(tmp > large_part.top()){
                        large_part.push(tmp);
                    }else{
                        large_part.push(small_part.top());
                        small_part.pop();
                        small_part.push(tmp);
                    }
                    median = large_part.top();
                }
            }
            if (j % 2 == 0)
            {
                cout << median;
                if (j != n - 1 && j != n - 2)
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}