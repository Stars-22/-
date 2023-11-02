#include <bits/stdc++.h>
using namespace std;
int main(){
	int l, r;
	int sum = 0;
	cin >> l >> r;
	for(; l<=r; l++){
		int a = l;
		while(a != a%10){
			if(a%10 == 2) sum++;
			a = a / 10;
		}
		if(a%10 == 2) sum++;
	}
	cout << sum;
    return 0;
}
