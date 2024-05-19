#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[1010], l = 0, r = 0, m, n, ans = 0, t;
	cin >> m >> n;
	for(int i=0; i<n; i++){
		cin >> t;
		bool k = false;
		for(int j=l; j<r; j++) if(a[j] == t) k = true;
		if(!k){
			if(r - l == m) l++;
			a[r++] = t;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
