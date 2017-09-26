#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

#define exrand(m) ((rand() * 100000L + rand()) % m)

int main() {
	srand(time(NULL));
	int n = exrand(1000L) + 1;
	int m = exrand(10000L) + 1;
	cout<<1<<endl<<n<<" "<<m<<endl;
	int a[n];
	for(int i=0;i<n;i++)
		a[i] = exrand(10000L)+1;
	sort(a, a+n, cmp);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}