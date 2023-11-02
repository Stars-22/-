#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	int a[100000], b[100000], c[100001];
	string name[100000];
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> a[i] >> name[i];
	for(int i=0; i<m; i++) cin >> b[i] >> c[i];
	int l = 0;
	for(int i=0; i<m; i++){
		if((b[i]==0 && a[l]==0) || (b[i]==1 && a[l]==1)){
			l = l - c[i];
			if(l < 0){
				l = ((-l)/n+1)*n + l;
			}
		}
		else if((b[i]==0 && a[l]==1) || (b[i]==1 && a[l]==0)){
			l = l + c[i];
			l = l % n;
		}
	}
	cout << name[l];
    return 0;
}
