#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string a[20];
	string ans;
	int k[20];
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) k[i] = 0;
	for(int i=0; i<n; i++){
		int m = 0;
		int num;
		while(true){
			int max = 0, mmax = 0;
			num = 0;
			for(int t=0; t<n; t++){
				if(k[t] == m){
					int x = m % a[t].size();
					if(a[t][x] > max) max = a[t][x];
				}
			}
			for(int t=0; t<n; t++){
				if(k[t] == m){
					int x = m % a[t].size();
					if(a[t][x] == max){
						if(a[t].size() > mmax) mmax = a[t].size();
						k[t] = m + 1;
						num++;
					}
				}
			}
			m++;
			if(num == 1) break;
			if(m > mmax) break;
		}
		int max = 0;
		for(int t=0; t<n; t++) if(k[t] > max) max = k[t];
		for(int t=0; t<n; t++){
			if(k[t] == max){
				k[t] = -1;
				ans = ans + a[t];
			}
			else if(k[t] > 0) k[t] = 0;
		}
	}
	cout << ans;
    return 0;
}
