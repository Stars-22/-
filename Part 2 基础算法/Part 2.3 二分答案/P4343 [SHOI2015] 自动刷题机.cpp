#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int main(){
	long long l, k;
	long long ans1 = -1;
	long long ans2 = -1;
	cin >> l >> k;
	for(int i=0; i<l; i++) cin >> a[i];
	long long l2 = 1;
	long long r2 = 1000000000000000001;
	long long mid;
	long long num;
	long long sum;
	while(l2 <= r2){
		mid = ( l2 + r2 ) / 2;
		num = 0;
		sum = 0;
		for(int i=0; i<l; i++){
			sum = sum + a[i];
			if(sum < 0) sum = 0;
			if(sum >= mid){
				sum = 0;
				num ++;
			}
		}
		if(num == k) ans1 = mid;
		if(num <= k)r2 = mid - 1;
		else l2 = mid + 1;
	}
	l2 = 1;
	r2 = 1000000000000000001;
	while(l2 <= r2){
		mid = ( l2 + r2 ) / 2;
		num = 0;
		sum = 0;
		for(int i=0; i<l; i++){
			sum = sum + a[i];
			if(sum < 0) sum = 0;
			if(sum >= mid){
				sum = 0;
				num ++;
			}
		}
		if(num == k) ans2 = mid;
		if(num < k) r2 = mid - 1;
		else l2 = mid + 1;
	}
	if(ans1 == -1) cout << "-1";
	else cout << ans1 << ' ' << ans2;
	return 0;
}
