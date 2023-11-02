#include <bits/stdc++.h>
using namespace std;
int main() {
	int w, n;
	cin >> w >> n;
	int a[201], b;
	for(int i=0; i<=w; i++) a[i] = 0;
	for(int i=0; i<n; i++){
		cin >> b;
		a[b] ++;
	}
	int ans = 0;
	for(int i=1; i<=w; i++){
		while(a[i] > 0){
			ans ++;
			a[i] --;
			for(int t=w-i; t>0; t--){
				if(a[t] > 0){
					a[t] --;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
