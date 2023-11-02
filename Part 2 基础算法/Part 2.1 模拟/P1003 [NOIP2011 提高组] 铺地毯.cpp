#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int k[4][10001];
	for(int i=0; i<n; i++)
		for(int t=0; t<4; t++)
			cin >> k[t][i];
	int a, b;
	cin >> a >> b;
	int ans = -1;
	for(int i=0; i<n; i++){
		if(a>=k[0][i] && a<=k[0][i]+k[2][i]-1){
			if(b>=k[1][i] && b<=k[1][i]+k[3][i]-1){
				ans = i+1;
			}
		}
	}
	cout << ans;
    return 0;
}
