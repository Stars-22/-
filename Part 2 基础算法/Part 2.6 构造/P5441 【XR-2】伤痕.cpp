#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << "0" << endl << "0";
		return 0;
	}
	cout << n * (n - 3) * (n*n + 6*n - 31) / 48;
	cout << endl;
	for(int i=1; i<=n; i++){
		for(int t=1; t<=n; t++)
			if(t > i && t< i+n/2+2)
				cout << "1 ";
			else if(i+n/2+2 > n && t < (i+n/2+2)-n)
				cout << "1 ";
			else cout << "0 ";
		cout << endl;
	}
	return 0;
}
