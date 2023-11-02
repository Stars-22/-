#include <bits/stdc++.h>
using namespace std;
int main(){
	int ans[100001];
	ans[0] = 1;
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) ans[i] = 0;
	for(int i=1; i<=n; i++){
		for(int t=i-1; t>=i-k; t--){
			if(t < 0) break;
			ans[i] = (ans[i] + ans[t]) % 100003;
		}
	}
	cout << ans[n];
    return 0;
}
