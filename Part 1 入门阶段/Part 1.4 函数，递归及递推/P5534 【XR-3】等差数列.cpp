#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a1, a2, n, an;
	cin >> a1 >> a2 >> n;
	an = a1 + (a2 - a1) * (n - 1);
	cout << (a1 + an) * n / 2;
    return 0;
}
