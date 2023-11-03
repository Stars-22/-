#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int main() {
	long long n;
	long long x;
	long long a1 = 0, a2 = 0, a_ = 0;
	cin >> n >> x;
	a_ = x;
	for(int i=2; i<=n; i++){
		scanf("%d", &x);
		a[i] = x - a_;
		a_ = x;
		if(a[i] > 0) a1 += a[i];
		if(a[i] < 0) a2 += -a[i];
	}
	cout << max(a1, a2) << endl << abs(a1 - a2) + 1;	
	return 0;
}
