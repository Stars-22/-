#include <bits/stdc++.h>
using namespace std;
char a[1000001];
int x[1000001], y[1000001];
int main() {
	int len = 1;
	bool k = false, k_ = false;
	while(a[len-1] != '\r' && a[len-1] != '\n') a[len++] = getchar();
	len -= 2;
	for(int i=len; i>0; i--){
		if(a[i] == 'Z'){
			if(k){
				k_ = true;
				break;
			}
			x[i] = 1;
			y[i] = 1;
			continue;
		}
		else{
			k = true;
			if(a[i] == 'X'){
				x[i] = 2;
				y[i] = 1;
			}
			else{
				x[i] = 1;
				y[i] = 2;
			}
		}
	}
	if(k_) cout << "-1";
	else{
		for(int i=1; i<=len; i++) cout << x[i];
		cout << endl;
		for(int i=1; i<=len; i++) cout << y[i];
	}
	return 0;
}
