#include <bits/stdc++.h>

using namespace std;

int ax, ay, bx, by;

int gcd(int x, int y){
    // Euclidean algorithm
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main(){
    // Pick's theorem ref: https://en.wikipedia.org/wiki/Pick%27s_theorem
    // ref: http://cleanbugs.com/item/poj2954triangle-for-the-entire-point-polygon-contains-the-entire-points-413551.html
    /*
 假设有一条由两个整点构成的线段,该线段该线段X方向的增量绝对值为DX, Y方向的增量绝对值为DY. 设线段内部(不含端点)整点个数为ans:

       DX==DY==0时, ans=0

       DX==0时, ans=DY-1(等价于gcd(DX,DY)-1 )

       DY==0时, ans=DX-1 (等价于gcd(DX,DY)-1 )

       DX!=0且DY!=0时, ans=gcd(DX,DY)-1

       简单说明一下上面结论:

       端点是整点的线段内部如果有整点, 那线段一定是被内部的整点均匀分割的.

假设线段内部有5个整点(这5个整点一定是均匀排列的),那么包括两端点共7个整点,线段被分成了6等份. 其实就是DX和DY分别被分成了6等份,\
那么说明DX和DY的最大公约数==6. 如果DX与DY的最大公约数==8,那么线段一定且最多能被分成8等份,且由于线段端点是整点,所以8等份的每个点都是整点.
*/
	while (cin >> ax >> ay >> bx >> by){
		if (ax == bx || ay == by) {
            cout << 0 << endl;
        }else{
            cout << gcd(abs(ax - bx), abs(ay - by)) - 1 << endl;
        } 
	}
	return 0;
} 
