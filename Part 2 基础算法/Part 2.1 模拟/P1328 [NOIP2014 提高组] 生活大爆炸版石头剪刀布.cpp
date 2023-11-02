#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[201], b[201];
	int n, na, nb;
	int la = 0, lb = 0, ansa = 0, ansb = 0;
	cin >> n >> na >> nb;
	for(int i=1; i<=na; i++) cin >> a[i];
	for(int i=1; i<=nb; i++) cin >> b[i];
	for(int i=1; i<=n; i++){
		la++; lb++;
		if(la > na) la = 1;
		if(lb > nb) lb = 1;
		if(a[la] == 0 && b[lb] == 1) ansb++;
		if(a[la] == 0 && b[lb] == 2) ansa++;
		if(a[la] == 0 && b[lb] == 3) ansa++;
		if(a[la] == 0 && b[lb] == 4) ansb++;
		if(a[la] == 1 && b[lb] == 0) ansa++;
		if(a[la] == 1 && b[lb] == 2) ansb++;
		if(a[la] == 1 && b[lb] == 3) ansa++;
		if(a[la] == 1 && b[lb] == 4) ansb++;
		if(a[la] == 2 && b[lb] == 0) ansb++;
		if(a[la] == 2 && b[lb] == 1) ansa++;
		if(a[la] == 2 && b[lb] == 3) ansb++;
		if(a[la] == 2 && b[lb] == 4) ansa++;
		if(a[la] == 3 && b[lb] == 0) ansb++;
		if(a[la] == 3 && b[lb] == 1) ansb++;
		if(a[la] == 3 && b[lb] == 2) ansa++;
		if(a[la] == 3 && b[lb] == 4) ansa++;
		if(a[la] == 4 && b[lb] == 0) ansa++;
		if(a[la] == 4 && b[lb] == 1) ansa++;
		if(a[la] == 4 && b[lb] == 2) ansb++;
		if(a[la] == 4 && b[lb] == 3) ansb++;
	}
	cout << ansa << ' ' << ansb;
    return 0;
}
