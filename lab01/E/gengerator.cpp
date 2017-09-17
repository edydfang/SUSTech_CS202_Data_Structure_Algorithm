#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("1.in", "w", stdout);
	srand((int)time(0));
	for (int ca = 0; ca < 1000; ca++){
		cout << rand() % 9 + 1;
		for (int i = 0; i < 8; i++){
			cout << rand() % 10;
		}
		cout << " ";
		for (int i = 0; i < 9; i++){
			cout << rand() % 10;
		}
		cout << " ";
		for (int i = 0; i < 9; i++){
			cout << rand() % 10;
		}
		cout << " ";
		for (int i = 0; i < 9; i++){
			cout << rand() % 10;
		}
		cout << endl;;
	}
	return 0;
}
