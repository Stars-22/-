#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[21];
int ans;
int sum_;

bool prime(int a){
	for(int i=2; i*i<=a; i++){
		if(a % i == 0) return false;
	}
	return true;
}

void sum(int loc, int k_){
	sum_ = sum_ + a[loc];
	if(k_ < k){
		for(int i=loc+1; i<=n; i++) sum(i, k_+1);
	}
	else if(prime(sum_)) ans++;
	sum_ = sum_ - a[loc];
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	sum(0, 0);
	cout << ans;
    return 0;
}
