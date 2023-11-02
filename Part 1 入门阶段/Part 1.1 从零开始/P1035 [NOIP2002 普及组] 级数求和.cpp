#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    double num = 0;
    int i = 0;
    cin>>k;
    while(true){
        i++;
        num = num + 1./i;
        if(num > k)break;
    }
    cout<<i;
    return 0;
}
