#include <bits/stdc++.h>
using namespace std;
int n, sum[100001], f[100001], b[100002];
struct home {int s, a;} a[100001];
bool k(home x, home y) {return x.a > y.a;}
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d", &a[i].s);
	for(int i=1; i<=n; i++) scanf("%d", &a[i].a);
	sort(a+1, a+1+n, k);
	for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i].a;
	for(int i=1; i<=n; i++) f[i] = max(f[i-1], a[i].s*2);
	for(int i=n; i>=1; i--) b[i] = max(b[i+1], a[i].s*2+a[i].a);
	for(int i=1; i<=n; i++) printf("%d\n", max(sum[i]+f[i], sum[i-1]+b[i]));
	return 0;
}
