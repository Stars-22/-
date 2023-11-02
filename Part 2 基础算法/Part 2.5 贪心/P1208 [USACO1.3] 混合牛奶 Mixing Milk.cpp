#include <bits/stdc++.h>
using namespace std;
struct milk{
	int p;
	int a;
};
milk o[5001];
bool k(milk a, milk b){
	return a.p < b.p;
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
		cin >> o[i].p >> o[i].a;
	sort(o, o + m, k);
	int ans = 0;
	int l = 0;
	while(n > 0){
		if(o[l].a >= n){
			ans = ans + o[l].p * n;
			n = 0;
		}
		else{
			ans = ans + o[l].p * o[l].a;
			n = n - o[l].a;
			l ++;
		}
	}
	cout << ans;
	return 0;
}
