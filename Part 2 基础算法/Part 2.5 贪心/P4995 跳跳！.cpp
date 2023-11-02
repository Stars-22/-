#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long a[301];
	bool b[301];
	for(int i=0; i<n; i++) b[i] = true;
	for(int i=0; i<n; i++) cin >> a[i];
	int l = 300;
	a[300] = 0;
	long long ans = 0;
	for(int t=0; t<n; t++){
		long long max = 0;
		int r;
		for(int i=0; i<n; i++){
			if(b[i] && abs(a[i] - a[l]) > max){
				max = abs(a[i] - a[l]);
				r = i;
			}
		}
		b[r] = false;
		ans = ans + max * max;
		l = r;
	}
	cout << ans << endl;
	return 0;
}
