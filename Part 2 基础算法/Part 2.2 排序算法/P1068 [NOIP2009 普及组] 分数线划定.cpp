#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int a[10000];
	for(int i=0; i<n; i++) a[i] = 0;
	int b[5001];
	int c[5001];
	for(int i=0; i<n; i++){
		cin >> c[i] >> b[i];
		a[c[i]] = b[i];
	}
	sort(b, b + n);
	sort(c, c + n);
	int s_ = m * 15 / 10;
	int s = b[n-s_];
	int sum = 0;
	for(int i=n-1; i>=0; i--){
		if(b[i] >= s){
			sum ++;
		}
	}
	cout << s << ' ' << sum << endl;
	for(int i=n-1; b[i]>=s; i--){
		for(int t=0; t<n; t++){
			if(a[c[t]] == b[i]){
				cout << c[t] << ' ' << a[c[t]] << endl;
				a[c[t]] = 0;
				break;
			}
		}
	}
    return 0;
}
