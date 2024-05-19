#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[100010] = {0}, p = 0, sum = 0, y;
	char x;
	cin >> a[p++];
	while(cin >> x >> y){
		if(x == '*') a[p-1] = (a[p-1] * y) % 10000;
		else a[p++] = y;
	}
	for(int i=0; i<p; i++) sum = (sum + a[i]) % 10000;
	cout << sum%10000;
	return 0;
}
