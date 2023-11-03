#include <bits/stdc++.h>
using namespace std;
long long n, c, a[1001], ans = 1e18, sum[1001];
void fama(long long num, int i){
	if(num - sum[i] > ans) return;
	ans = min(ans, num);
	for(; i>0; i--)
		if(a[i] <= num)
			fama(num - a[i], i-1);
}
int main() {
	cin >> n >> c;
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	fama(c, n);
	cout << c - ans;
	return 0;
}
