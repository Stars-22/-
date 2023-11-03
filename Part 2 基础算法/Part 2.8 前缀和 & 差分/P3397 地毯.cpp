#include <bits/stdc++.h>
using namespace std;
	int a[1002][1002];
int main() {
	memset(a, 0, sizeof(a));
	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	for(int i=1; i<=m; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int t=y1; t<=y2; t++){
			a[t][x1] ++;
			a[t][x2+1] --;
		}
	}
//	for(int i=1; i<=n; i++){
//		for(int t=1; t<=n; t++){
//			cout << a[i][t] << ' ';
//		}
//		cout << endl;
//	}
	for(int t=1; t<=n; t++){
		for(int i=1; i<=n; i++){
			a[i][t] = a[i][t] + a[i][t-1];
			cout << a[i][t] << ' ';
		}
		cout << endl;
	}
	return 0;
}
