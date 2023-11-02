#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a;
	cin >> b;
	int al = a.size() - 1;
	int bl = b.size() - 1;
	char c;
	int d = 0;
	string ans = "";
	while(bl >= 0 || al >= 0) {
		c = 0;
		if(al >= 0) c = c + a[al] - '0';
		if(bl >= 0) c = c + b[bl] - '0';
		c = c + d;
		d = 0;
		if(c >= 10){
			d ++;
			c = c - 10;
		}
		c = c + '0';
		ans = ans + c;
		al --;
		bl --;
	}
	if(d == 1) cout << "1";
	for(int i=ans.size()-1; i>=0; i--) cout << ans[i];
	return 0;
}
