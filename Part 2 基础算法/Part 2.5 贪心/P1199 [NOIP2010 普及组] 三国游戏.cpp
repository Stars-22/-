#include <bits/stdc++.h>
using namespace std;
int a[501][501];
int main() {
	int n;
	cin >> n;
	for(int i=1; i<=n-1; i++){
		for(int t=i+1; t<=n; t++){
			cin >> a[i][t];
			a[t][i] = a[i][t];
		}
	}
	int ans = 0;
	for(int i=1; i<=n; i++) a[i][i] = 0;
	for(int i=1; i<=n; i++){
		sort(a[i] + 1, a[i] + n + 1);
		ans = max(ans, a[i][n-1]);
	}
	cout << "1" << endl << ans;
	return 0;
}
