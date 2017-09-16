#include<bits/stdc++.h>

using namespace std;

const int N = 1234;

int A[N], B[N], C[N];
string a, b;

int main(){
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	while (cin >> a >> b){
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(C, 0, sizeof(C));
		int la = a.length();
		int lb = b.length();
		int t = 0, maxlen = max(la, lb);
		for (int i = a.length() - 1; i >= 0; i--) A[t++] = a[i] - '0';
		t = 0;
		for (int i = b.length() - 1; i >= 0; i--) B[t++] = b[i] - '0';
		int carry= 0;
		for (int i = 0; i < maxlen; i++){
			C[i] = (A[i] + B[i] + carry) % 10;
			carry = (A[i] + B[i] + carry) / 10;
		 }
		 if(carry){
			C[maxlen++]=carry;
		 }
		 
		if (C[maxlen] > 0) maxlen++;
		for (int i = maxlen-1 ; i >-1; i--) cout << C[i];
		cout << endl;
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
} 
