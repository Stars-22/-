#include <bits/stdc++.h>
using namespace std;
int main(){
	char a;
	int p = 0;
	int b[1000];
	while((a = getchar()) != '@'){
		if(a >= '0' && a <= '9'){
			b[p] = 0;
			while(a != '.'){
				b[p] = b[p] * 10 + a - '0';
				a = getchar();
			}
			p++;
		}
		if(a == '.') continue;
		int y = b[--p];
		int x = b[--p];
		if(a == '*') b[p++] = x * y;
		if(a == '/') b[p++] = x / y;
		if(a == '+') b[p++] = x + y;
		if(a == '-') b[p++] = x - y;
	}
	cout << b[--p];
	return 0;
}
