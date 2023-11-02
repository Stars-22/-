#include <bits/stdc++.h>
using namespace std;
void er(int a);
void printEr(int a);
void er(int a) {
	int i=0;
	int num = 1;
	for(; i<=16; i++) {
		if(num == a) break;
		if(num > a) {
			num = num / 2;
			i --;
			break;
		}
		num  = num * 2;
	}
	if(num == a) printEr(i);
	else {
		printEr(i);
		cout << "+";
		er(a - num);
	}
}
void printEr(int a) {
	if(a == 1) cout << "2";
	else if(a == 0) cout << "2(0)";
	else {
		cout << "2(";
		er(a);
		cout << ")";
	}
}
int main() {
	int n;
	cin >> n;
	er(n);
	return 0;
}
