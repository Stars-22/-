#include <bits/stdc++.h>
using namespace std;
struct xy{
	long long x;
	long long y;
};
xy a[200001];
bool k(xy x, xy y){
	if(x.x != y.x) return x.x < y.x;
	return x.y < y.y;
}
int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i].x >> a[i].y;
	sort(a, a + n, k);
	long long ans = 1e19, x2, y2;
	for(int i=0; i<n; i++){
		for(int t=i+1; t<n; t++){
			x2 = pow((a[t].x - a[i].x), 2);
			if(x2 >= ans) break;
			y2 = pow((a[t].y - a[i].y), 2);
			if(x2 + y2 < ans) ans = x2 + y2;
		}
	}
	double ans_ = ans;
	printf("%.4f", sqrt(ans_));
	return 0;
}
