#include <bits/stdc++.h>
using namespace std;
int a[39][39];
int main(){
	int n;
	cin >> n;
	a[0][n/2] = 1;
	int k1 = 0, k2 = n/2;
	for(int i=2; i<=n*n; i++){
		if(k1 == 0 && k2 != n-1){
			k1 = n-1;
			k2 = k2 + 1;
			a[k1][k2] = i;
			continue;
		}
		if(k1 != 0 && k2 == n-1){
			k1 = k1 - 1;
			k2 = 0;
			a[k1][k2] = i;
			continue;
		}
		if(k1 == 0 && k2 == n-1){
			k1 = k1 + 1;
			a[k1][k2] = i;
			continue;
		}
		if(k1 != 0 && k2 != n-1){
			if(a[k1-1][k2+1] == 0){
				k1 = k1 - 1;
				k2 = k2 + 1;
				a[k1][k2] = i;
			}
			else{
				k1 = k1 + 1;
				a[k1][k2] = i;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int t=0; t<n; t++){
			cout << a[i][t] << ' ';
		}
		cout << endl;
	}
    return 0;
}
