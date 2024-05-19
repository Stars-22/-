#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[1000], pb = 0, pd = 0;
	char b[1000], d[1000];
	string c;
	cin >> c;
	for(int i=0; i<c.size(); i++){
		if(c[i] >= '0' && c[i] <= '9'){
			b[pb] = 'n';
			a[pb++] = c[i] - '0';
		}
		if(c[i] == '^') d[pd++] = c[i];
		if(c[i] == '*' || c[i] == '/'){
			while(pd != 0 && d[pd-1] != '(' && (d[pd-1] != '+' && d[pd-1] != '-')) b[pb++] = d[--pd];
			d[pd++] = c[i];
		}
		if(c[i] == '+' || c[i] == '-'){
			while(pd != 0 && d[pd-1] != '(') b[pb++] = d[--pd];
			d[pd++] = c[i];
		}
		if(c[i] == '(') d[pd++] = c[i];
		if(c[i] == ')') while(d[--pd] != '(') b[pb++] = d[pd];
	}
	while(pd > 0) b[pb++] = d[--pd];
	while(pb > 1){
		for(int i=0; i<pb; i++){
			if(b[i] == 'n') cout << a[i] << ' ';
			else cout << b[i] << ' ';
		}
		cout << endl;
		for(int i=0; i<pb; i++){
			if(b[i] != 'n'){
				if(b[i] == '+') a[i-2] = a[i-2] + a[i-1];
				if(b[i] == '-') a[i-2] = a[i-2] - a[i-1];
				if(b[i] == '*') a[i-2] = a[i-2] * a[i-1];
				if(b[i] == '/') a[i-2] = a[i-2] / a[i-1];
				if(b[i] == '^') a[i-2] = pow(a[i-2], a[i-1]);
				pb -= 2;
				for(int j=i-1; j<pb; j++){
					b[j] = b[j+2];
					a[j] = a[j+2];
				}
				break;
			}
		}
	}
	cout << a[--pb];
	return 0;
}
