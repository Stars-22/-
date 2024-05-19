#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		long long n, ans[100] = {0}, num = 0, a, b, maxb, n_;
		cin >> n;
		for(a=1; n!=0; a*=2){
			for(b=1,maxb = 0; (n_=a * b)<=n; b *= 3) 
				if((n - n_) % (a * 2) == 0) maxb = b;
			if(maxb != 0) 
				n -= (ans[num++] = a * maxb);
		}
		cout << num << endl;
		for(int j=0; j<num; j++) cout << ans[j] << ' ';
		cout << endl;
	}
    return 0;
}
