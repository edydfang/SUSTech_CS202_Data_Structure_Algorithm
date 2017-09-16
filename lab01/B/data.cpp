#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("1.in", "w", stdout);
	srand((unsigned int)time(0));
	for (int i = 0; i < 50; i++){
		cout << rand() % 9 + 1;
		for (int j = 0; j < 999; j++){
			cout << rand() % 9;
		}
		cout << " ";
		cout << rand() % 8 + 1;
		for (int j = 0; j < 999; j++){
			cout << rand() % 10;
		}
		cout << endl;
	}
	fclose(stdout);
	return 0;
} 
