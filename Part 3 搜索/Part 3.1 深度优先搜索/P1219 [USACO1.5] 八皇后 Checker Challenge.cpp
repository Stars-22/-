#include <bits/stdc++.h>
using namespace std;
bool a[14], b[26], c[26];
int n;
int num = 0, ans[14];
int huanghou(int d){
	if(d > n) return 0;
	for(int i=1; i<=n; i++){
		if(a[i] == true) continue;
		if(b[i-d+n-1] == true) continue;
		if(c[n*2-i-d] == true) continue;
		a[i] = true;
		b[i-d+n-1] = true;
		c[n*2-i-d] = true;
		ans[d] = i;
		if(d < n) huanghou(d + 1);
		else {
			if(num < 3){
				for(int j=1; j<=n; j++) cout << ans[j] << ' ';
				cout << endl;
			}
			num ++;
		}
		a[i] = false;
		b[i-d+n-1] = false;
		c[n*2-i-d] = false;
	}
	return 0;
}
int main() {
	cin >> n;
	huanghou(1);
	cout << num;
	return 0;
}
