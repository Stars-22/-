#include <bits/stdc++.h>
using namespace std;
int a[1002][1002];
int b[10000000][2];
bool c[1002][1002];
int main(){
	int m, n;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int t=1; t<=m; t++){
			scanf("%d", &a[i][t]);
		}
	}
	for(int i=1; i<1001; i++){
		a[i][0] = 10000;
		a[0][i] = 10000;
		a[i][n+1] = 10000;
		a[n+1][i] = 10000;
	}
	int l = 0;
	int r = 1000;
	int mid;
	int b_l = 0;
	int b_r = 0;
	bool k = false;
	while(l != r-1){
		b_l = 0;
		b_r = 0;
		k = false;
		mid = ( l + r ) / 2;
		memset(c, 0, sizeof(c));
		for(int i=1; i<=m; i++){
			if(a[2][i] <= mid){
				b[b_r][0] = 2;
				b[b_r][1] = i;
				b_r ++;
				c[2][i] = true;
			}
		}
		while(b_l < b_r){
			if(b[b_l][0]+1 == n){
				k = true;
				break;
			}
			if(a[b[b_l][0]][b[b_l][1]+1] <= mid && !c[b[b_l][0]][b[b_l][1]+1]){
				b[b_r][0] = b[b_l][0];
				b[b_r][1] = b[b_l][1]+1;
				b_r ++;
				c[b[b_l][0]][b[b_l][1]+1] = true;
			}
			if(a[b[b_l][0]][b[b_l][1]-1] <= mid && !c[b[b_l][0]][b[b_l][1]-1]){
				b[b_r][0] = b[b_l][0];
				b[b_r][1] = b[b_l][1]-1;
				b_r ++;
				c[b[b_l][0]][b[b_l][1]-1] = true;
			}
			if(a[b[b_l][0]-1][b[b_l][1]] <= mid && !c[b[b_l][0]-1][b[b_l][1]]){
				b[b_r][0] = b[b_l][0]-1;
				b[b_r][1] = b[b_l][1];
				b_r ++;
				c[b[b_l][0]-1][b[b_l][1]] = true;
			}
			if(a[b[b_l][0]+1][b[b_l][1]] <= mid && !c[b[b_l][0]+1][b[b_l][1]]){
				b[b_r][0] = b[b_l][0]+1;
				b[b_r][1] = b[b_l][1];
				b_r ++;
				c[b[b_l][0]+1][b[b_l][1]] = true;
			}
			b_l ++;
		}
		if(k){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << l+1;
    return 0;
}
