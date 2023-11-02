#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, m;
    bool tree[10001];
    int sum = 0;
    cin>>l>>m;
    for(int i=0; i<=l; i++) tree[i] = true;
    int under1, under2;
    for(int i=0; i<m; i++){
    	cin>>under1>>under2;
    	for(int t=under1; t<=under2; t++){
    		tree[t] = false;
		}
	}
	for(int i=0; i<=l; i++){
		if(tree[i] == true) sum++;
	}
	cout<<sum;
    return 0;
}
