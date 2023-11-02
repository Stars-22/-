#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int sum = 0;
    while(true){
    	if(N == 0)break;
    	sum = sum * 10 + N%10;
    	N = N / 10;
	}
	cout<<sum;
    return 0;
}
