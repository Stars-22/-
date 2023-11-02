#include <bits/stdc++.h>
using namespace std;
int a[510001], b[510001];
long long sum = 0;
void merge(int x, int y){
	if(x == y) return;
	merge(x, (x+y)/2);
	merge((x+y)/2+1, y);
	int l1 = x, l2 = (x+y)/2 + 1;
	int l = x;
	while(l1 <= (x+y)/2 && l2 <= y){
		if(a[l1] > a[l2]){
			b[l] = a[l2];
			l++;
			l2++;
			sum = sum + ( x + y ) / 2 - l1 + 1;
		}
		else{
			b[l] = a[l1];
			l++;
			l1++;
		}
	}
	for(; l1<=(x+y)/2; l1++,l++){
		b[l] = a[l1];
	}
	for(; l2<=y; l2++,l++){
		b[l] = a[l2];
	}
	for(int i=x; i<=y; i++){
		a[i] = b[i];
	}
}
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	merge(0, n-1);
	cout << sum;
    return 0;
}
