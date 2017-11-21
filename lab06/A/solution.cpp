#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, i, x, height, l, r, mid;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin>>x;
        l = 0, r = 10;
        while(l+1<r){
            mid = (l + r)/2;
            //cout << "gg" << (1 << mid+1) -1 << endl;
            if((1 << mid+1) -1 < x){
                l = mid;
            }else{
                r = mid;
            }
        }
        if((1 << l+1) -1 < x){
            l++;
        }
        cout << l << endl;
    }

    return 0;
}
