#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int sum = 0;
    for(int i=1; i<=n; i++){
    	int num = i;
    	while(true){
    		if(num-num/10*10 == x)sum++;
    		if(num%10 == num)break;
    		num = num/10;
		}
	}
    cout<<sum;
    return 0;
}
