#include <bits/stdc++.h>
using namespace std;
int a[50002];
int main(){
	int ll, n, m;
	cin >> ll >> n >> m;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	a[0] = 0;
	a[n+1] = ll;
	int l = 0;
	int r = ll+1;
	int mid;
	while(l != r-1){
		mid = ( l + r ) / 2;
		int num = 0;
		bool k = true;
		for(int t=0; t<=n; ){
			int o = t + 1;
			for(; o<=n+1; o++){
				if(a[o] - a[t] >= mid) break;
				num ++;
			}
			t = o;
			if(num > m){
				k = false;
				break;
			}
		}
		if(k){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	cout << l;
    return 0;
}
