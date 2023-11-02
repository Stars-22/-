#include <bits/stdc++.h>
using namespace std;
string a;
long long b, num, n = 1;
int main() {
	cin >> a >> b;
	for(num=a.size(); num<b; num*=2) n++;
	for(int i=1; i<n; i++) {
		num = num / 2;
		if(b == num * 2) b = num - 1;
		else if(b == num + 1) b = num;
		else if(b > num) b = b - num - 1;
	}
	cout << a[b-1];
	return 0;
}
