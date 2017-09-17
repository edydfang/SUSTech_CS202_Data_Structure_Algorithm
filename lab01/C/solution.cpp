#include <bits/stdc++.h>

using namespace std;

const int N = 30;
// n: number of cards a: used to store the number of certain card in hand
int a[N], n; 
string s;
string mp[15] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "WJ", "RJ"};

void map_to(string s, int x){
	if (s == "RJ"){
		a[14] = 4;	 // special case
	}else if (s == "WJ"){
		a[13] = 4;
	}else if (s == "2"){
		a[12]++;
	}else if (s == "A"){
		a[11]++;
	}else if (s == "K"){
		a[10]++;
	}else if (s == "Q"){
		a[9]++;
	}else if (s == "J"){
		a[8]++;
	}else if (s == "10"){
		a[7]++;	
	}else{
		char ch = s[0];
		a[ch - '0' - 3]++;
	}
} 

int main(){
	while (cin >> s){
		memset(a, 0, sizeof(a));
		if (s == "Farmer"){
			n = 17;
		}else if (s == "Dizhu"){
			n = 20;
		}
		for (int i = 0; i < n; i++){
			cin >> s;
			map_to(s, i);
		}
		int t = 0;
		for (int j = 4; j > 0; j--){ // sort by the number of certain cards
			for (int i = 14; i > -1; i--){ // tranverse all the cards
				if (a[i] == j){
					for (int k = 0; k < j; k++){
						cout << mp[i];
						t++;
						if (t == n) cout << endl; 
						else cout << " "; // output whitespace or \n
						if (i > 12) break; // for the RJ or BJ, only print once
					}
				}
			}
		}
	}
	return 0;
} 
