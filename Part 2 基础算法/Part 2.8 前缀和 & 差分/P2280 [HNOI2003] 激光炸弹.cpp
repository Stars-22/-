#include <bits/stdc++.h>
using namespace std;
int a[5002][5002];
int main() {
	memset(a, 0, sizeof(a));
	int n, m, x, y, z;
	int ans = 0;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> x >> y >> z;
		a[x+1][y+1] += z;
	}
	for(int i=1; i<=5001; i++)
		for(int t=1; t<=5001; t++)
			a[i][t] += a[i][t-1];
	for(int i=1; i<=5001; i++)
		for(int t=1; t<=5001; t++)
			a[t][i] += a[t-1][i];
	for(int i=m; i<=5001; i++){
		for(int t=m; t<=5001; t++){
			int b = a[i][t] - a[i-m][t] - a[i][t-m] + a[i-m][t-m];
			//cout << b << endl;
			ans = max(ans, b);
		}
	}
	cout << ans;
	return 0;
} 
