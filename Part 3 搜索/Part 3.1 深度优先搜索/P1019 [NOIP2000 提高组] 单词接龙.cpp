#include <bits/stdc++.h>
using namespace std;
string a[20];
int n;
int b[20][20];
int c[20];
int ans = 0;
int num;
bool d[20];
int jielong(int x){
	for(int i=0; i<n; i++){
		if(!c[i]) continue;
		if(x == -1 && !d[i]) continue;
		if(x == -1 && d[i]){
			c[i] --;
			num += a[i].size();
			ans = max(ans, num);
			jielong(i);
			num -= a[i].size();
			c[i] ++;
		}
		else if(b[x][i]){
			c[i] --;
			num = num + a[i].size() - b[x][i];
			//cout << x << ' ' << i << ' ' << num << endl;
			ans = max(ans, num);
			jielong(i);
			num = num - a[i].size() + b[x][i];
			c[i] ++;
		}
	}
	return 0;
}
int main() {
	char e;
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	cin >> e;
	memset(d, 0, sizeof(d));
	memset(b, 0, sizeof(b));
	for(int i=0; i<n; i++)
		if(a[i][0] == e) d[i] = true;
	for(int i=0; i<20; i++) c[i] = 2;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=a[i].size()-1; k>=0; k--){
				if(a[i][k] == a[j][0]){
					int sum = 0;
					for(int l=k; l<a[i].size() && l-k<a[j].size()-1; l++)
						if(a[i][l] == a[j][l-k]) sum ++;
					if(sum == a[i].size() - k){
						b[i][j] = sum;
						break;
					}
				}
			}
		}
	}
	jielong(-1);
	cout << ans;
	return 0;
}
