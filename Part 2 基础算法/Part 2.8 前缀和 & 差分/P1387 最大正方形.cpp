#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[101][101];
	int n, m;
	cin >> n >> m;
	int b;
	for(int i=1; i<=n; i++){
		for(int t=1; t<=m; t++){
			scanf("%d", &b);
			if(a[i][t-1] != 0 && b == 1){
				a[i][t] = a[i][t-1] + 1;
			}
			else{
				a[i][t] = b;
			}
		}
	}
	int ans = 0, k;
	for(int i=1; i<=m; i++){
		for(int t=1; t<=n; t++){
			if(a[t][i] == 0) continue;
			k = 0;
			for(int j=t; j<t+a[t][i] && j<=n; j++){
				if(a[j][i] < a[t][i]) break;
				k ++;
			}
			for(int j=t; j>t-a[t][i] && j>=1; j--){
				if(a[j][i] < a[t][i]) break;
				k ++;
			}
			if(k - 1 >= a[t][i]){
				ans = max(ans, a[t][i]);
			}
		}
	}
	cout << ans;
	return 0;
}
