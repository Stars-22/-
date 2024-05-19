#include <bits/stdc++.h>
using namespace std;
struct road {int x, y, t; }a[100010];
int compare(road x, road y) {return x.t < y.t; }
int c[1010][1010] = {0};
int n, m, num = 0, bmax = 0;
int k[1010] = {0};
int b[100010] = {0};
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++) cin >> a[i].x >> a[i].y >> a[i].t;
	sort(a, a+m, compare);
	for(int i=0; i<m; i++){
		if(!k[a[i].x] && !k[a[i].y]){
			num++;
			k[a[i].x] = num;
			k[a[i].y] = num;
			bmax = max(bmax, ++++b[num]);
		}
		else{
			if(k[a[i].x] != k[a[i].y]){
				if(k[a[i].x] && k[a[i].y]){
					int min_ = min(k[a[i].x], k[a[i].y]);
					int max_ = max(k[a[i].x], k[a[i].y]);
					for(int j=1; j<=n; j++){
						if(k[j] == max_){
							k[j] = min_;
							if(min_ == 1) bmax = max(bmax, ++b[min_]);
						}
					}
				}
				else{
					int max_ = max(k[a[i].x], k[a[i].y]);
					k[a[i].x] = max_;
					k[a[i].y] = max_;
					bmax = max(bmax, ++b[max_]);
				}
			}
		}
//		for(int j=1; j<=n; j++){
//			cout << k[j] << ' ';
//		}
//		cout << "    " << sum;
//		cout << endl;
		if(bmax == n){
			cout << a[i].t;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
