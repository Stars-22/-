#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k[1001];
	cin >> n;
	k[1] = 1;
	for(int i=2; i<=n; i++){
		k[i] = 1;
		for(int t=1; t<=i/2; t++){
			k[i] = k[i] + k[t];
		}
	}
	cout << k[n];
    return 0;
}
