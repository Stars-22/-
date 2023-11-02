#include <bits/stdc++.h> 
using namespace std;
struct Person{
	int name;
	int fen;
	int able;
	bool operator<(Person t){
		if(fen!=t.fen)return fen>t.fen;
		return name<t.name;
	}
};

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, r, q;
	Person a[200001];
	cin >> n >> r >> q;
	for(int i=1; i<=n*2; i++){
		a[i].name = i;
		cin >> a[i].fen;
	}
	for(int i=1; i<=n*2; i++) cin >> a[i].able;
	for(int i=0; i<r; i++){
		sort(a+1, a+n*2+1);
		for(int t=1; t<=n*2; t=t+2){
			if(a[t].able > a[t+1].able) a[t].fen++;
			else a[t+1].fen++;
		}
	}
	sort(a+1, a+n*2+1);
	cout << a[q].name;
    return 0;
}
