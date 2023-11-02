#include <bits/stdc++.h>
using namespace std;
int sum;
void ans(int n, int k, int r){
	if(r == 0 && k == 0) sum++;
	if(k != 0){
		for(int i=n; i<=r; i++) ans(i, k-1, r-i);
	}
	
}
int main(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n-k; i++) ans(i, k-1, n-i);
	cout << sum;
    return 0;
}
