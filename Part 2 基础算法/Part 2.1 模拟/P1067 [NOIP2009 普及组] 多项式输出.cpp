#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	if(n > 1){
		cin >> a;
		if(a > 1 || a < -1) cout << a << "x^" << n;
		if(a == 1) cout << "x^" << n;
		if(a == -1) cout << '-' << "x^" << n;	
	}
	if(n == 1){
		cin >> a;
		if(a > 1 || a < -1) cout << a << "x";
		if(a == 1) cout << "x";
		if(a == -1) cout << '-' << "x";	
	}
	for(int i=n-1; i>1; i--){
		cin >> a;
		if(a > 1) cout << '+' << a << "x^" << i;
		if(a == 1) cout << '+' << "x^" << i;
		if(a == 0) continue;
		if(a == -1) cout << '-' << "x^" << i;
		if(a < -1) cout << a << "x^" << i;
	}
	if(n > 1){
		cin >> a;
		if(a > 1) cout << '+' << a << 'x';
		if(a == 1) cout << "+x";
		if(a == -1) cout << "-x";
		if(a < -1) cout << a << 'x';
	}
	if(n > 0){
		cin >> a;
		if(a > 0) cout << '+' << a;
		if(a < 0) cout << a;	
	}
	if(n == 0){
		cin >> a;
		if(a != 0) cout << a;
	}
    return 0;
}
