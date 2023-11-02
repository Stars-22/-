#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b, long long p){
    long long ans = 0;
    while(b > 0){
        if(b % 2 != 0) ans = ( ans + a ) % p;
        a = ( a * 2 ) % p;
        b = b / 2;
    }
    return ans;
}
long long powp(long long a, long long b, long long p){
    if(b == 0) return 1;
	long long ans = 1;
    if(b != 1) ans = powp(a, b/2, p);
    if(b % 2 == 0){
        return mul(ans, ans, p);
    }
    else{
        return mul(mul(ans, ans, p), a, p);
    }
}
int main(){
    long long a, b, p;
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=';
    a = a % p;
    cout << powp(a, b, p) << endl;
    return 0;
}
