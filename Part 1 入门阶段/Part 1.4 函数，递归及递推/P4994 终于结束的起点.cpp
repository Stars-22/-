#include <bits/stdc++.h>
using namespace std;
int main(){
	int fib[10000001];
	int m;
	bool k;
	cin >> m;
	fib[0] = 0;
	fib[1] = 1;
	int i = 2;
	for(; ; i++){
		fib[i] = (fib[i-1] + fib[i-2]) % (m*10);
		if(k && fib[i]%m == 1){
			break;
		}
		if(k) k = false;
		if(fib[i]%m == 0) k = true;
	}
	cout << i-1;
    return 0;
}
