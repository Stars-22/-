#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long x;
	long long y;
	long long z;
	long long k = 0;
}a[1010];
bool isDist(Node a, Node b, long long r){
	long long Dist_2 = (a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
	long long r2_2 = r * r * 4;
	return Dist_2 <= r2_2;
}
int main(){
	long long t, x, y, z, n, h, r, up[1010], down[1010];
	cin >> t;
	for(long long i=1; i<=t; i++){
		cin >> n >> h >> r;
		long long num = 0;
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));
		memset(a, 0, sizeof(a));
		for(long long j=1; j<=n; j++){
			cin >> a[j].x >> a[j].y >> a[j].z;
			for(long long k=1; k<j; k++){
				if(isDist(a[k], a[j], r)){
					if(a[j].k == 0){
						a[j].k = a[k].k;
						up[a[k].k] = max(up[a[k].k], a[j].z+r);
						down[a[k].k] = min(down[a[k].k], a[j].z-r);
					}
					if(a[j].k != a[k].k){
						for(long long l=1; l<=j; l++){
							if(a[l].k == a[j].k){
								a[l].k = a[k].k;
								up[a[k].k] = max(up[a[k].k], a[l].z+r);
								down[a[k].k] = min(down[a[k].k], a[l].z-r);
							}
						}
					}
				}
			}
			if(a[j].k == 0){
				a[j].k = ++num;
				up[a[j].k] = a[j].z + r;
				down[a[j].k] = a[j].z - r;
			}
		}
		bool ans = 0;
		for(long long j=1; j<=num; j++){
			if(up[j] >= h && down[j] <= 0){
				ans = 1;
				break;
			}
		}
		//cout << num << ' ' << up[1] << ' ' << down[1] << ' ';
		if(ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
