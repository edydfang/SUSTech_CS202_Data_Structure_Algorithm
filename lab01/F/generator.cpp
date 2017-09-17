#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("1.in", "w", stdout);
	srand((int)time(0));
	for (int ca = 0; ca < 1000; ca++){
		int n = rand() % 1000 + 1, k = rand() % 10000 + 1;
		cout << n << " " << k << endl;
		
		for (int i = 0; i < n; i++){
			cout << rand() % 9 + 1 << '.' << rand() % 10  << rand() % 10 << " "; 
		}
	}
	fclose(stdout);
	return 0;
}
