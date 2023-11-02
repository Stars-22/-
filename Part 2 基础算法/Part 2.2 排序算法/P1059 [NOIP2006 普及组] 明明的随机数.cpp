#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[101];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a + n);
	int k = 0;
	int b[101];
	int num = 0;
	for(int i=0; i<n; i++) {
		if(a[i] == k) continue;
		else {
			k = a[i];
			b[num] = a[i];
			num ++;
		}
	}
	cout << num << endl;
	for(int i=0; i<num; i++) cout << b[i] << ' ';
    return 0;
}
