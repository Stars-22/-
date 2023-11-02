#include <bits/stdc++.h>
using namespace std;
long long w[200001], v[200001];
long long l[200001], r[200001];
long long x1[200001], x2[200001];
int main(){
	long long n, m, s;
	cin>> n >> m >> s;
	for(int i=1; i<=n; i++) cin >> w[i] >> v[i];
	for(int i=1; i<=m; i++) cin >> l[i] >> r[i];
	long long l2 = 1;
	long long r2 = 1000000000001;
	long long mid;
	long long sum, ans = -1;
	while(true){
		mid = ( l2 + r2 ) / 2;
		memset(x1, 0, sizeof(x1));
		memset(x2, 0, sizeof(x2));
		for(int i=1; i<=n; i++){
			if(w[i] >= mid){
				x1[i] = x1[i-1] + 1;
				x2[i] = x2[i-1] + v[i];
			}
			else{
				x1[i] = x1[i-1];
				x2[i] = x2[i-1];
			}
		}
		sum = 0;
		for(int i=1; i<=m; i++){
			sum = sum + (x1[ r[i] ] - x1[ l[i]-1 ]) * (x2[ r[i] ] - x2[ l[i]-1 ]);
		}
		if(ans == -1) ans = abs(sum - s);
		if(ans > abs(sum - s)) ans = abs(sum - s);
		if( l2 == r2 - 1 ) break;
		if(sum >= s){
			l2 = mid;
		}
		else{
			r2 = mid;
		}
	}
	cout << ans;
    return 0;
}
