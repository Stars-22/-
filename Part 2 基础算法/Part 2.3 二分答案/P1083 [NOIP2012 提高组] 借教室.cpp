#include <bits/stdc++.h>
using namespace std;
long long r[1000001];
long long d[1000001], s[1000001], t[1000001];
long long b[1000001]; //每天对比上一天需求的教室数的变化量 
int main(){
	long long n, m;
	cin >> n >> m;
	for(long long i=1; i<=n; i++) scanf("%ld", &r[i]);
	for(long long i=1; i<=m; i++){
		scanf("%ld %ld %ld", &d[i], &s[i], &t[i]);
		b[s[i]] = b[s[i]] + d[i];
		b[t[i]+1] = b[t[i]+1] - d[i];
		// cout << b[s[i]] << ' ' << b[t[i]] << endl;
	}
	long long sum_ = 0; //当天需求的教室数 
	long long ans = -1;
	for(long long i=1; i<=n; i++){
		sum_ = sum_ + b[i];
		for(long long j=m, num = 0; r[i] < sum_; j--){
			b[s[j]] = b[s[j]] - d[j];
			b[t[j]+1] = b[t[j]+1] + d[j];
			if(s[j] <= i && t[j] >= i){
				sum_ = sum_ - d[j];
			}
			if(r[i] >= sum_ ){
				if(ans != -1) ans = min(ans, j);
				else ans = j;
			}
		}
	}
	if(ans == -1) cout << '0';
	else{
		cout << "-1" << endl;
		cout << ans;
	}
	return 0;
}
