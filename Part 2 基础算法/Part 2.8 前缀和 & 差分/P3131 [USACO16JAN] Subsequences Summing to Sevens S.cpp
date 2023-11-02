#include <bits/stdc++.h>
using namespace std;
long long a[50001];
int main() {
	int n;
	cin >> n;
	int b;
	a[0] = 0;
	for(int i=1; i<=n; i++){
		scanf("%d", &b);
		a[i] = a[i-1] + b;
	}
	int ans = 0;
	int ansl, ansr;
	for(int i=0; i<=6; i++){
		ansl = n;
		ansr = n;
		for(int t=0; t<=n; t++)
			if(a[t] % 7 == i){
				ansl = t;
				ansr = t;
				break;
			}
		for(int t=ansl+1; t<=n; t++){
			if(a[t] % 7 == i && a[t] >= 7)
				ansr = t;
		}
		if(ansr == ansl && a[ansr] >= 7) ansr ++;
		ans = max(ans, ansr - ansl);
	}
	cout << ans;
	return 0;
}
