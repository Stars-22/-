#include <bits/stdc++.h>
using namespace std;
int main(){
	string model[100001], Rin[100001];
	int modelnum = 0, Rinnum = 0;
	for(; ; modelnum++){
		getline(cin, model[modelnum]);
		if(model[modelnum] == "EOF") break;
		for(int i=0; i<model[modelnum].size(); i++){
			if(model[modelnum][i] == '<'){
				if(i == 0){
					model[modelnum].erase(0, 1);
					i = i - 1;
				}
				else {
					model[modelnum].erase(i-1, 2);
					i = i - 2;
				}
			}
		}
	}
	for(; ; Rinnum++){
		getline(cin, Rin[Rinnum]);
		if(Rin[Rinnum] == "EOF") break;
		for(int i=0; i<Rin[Rinnum].size(); i++){
			if(Rin[Rinnum][i] == '<'){
				if(i == 0){
					Rin[Rinnum].erase(0, 1);
					i = i - 1;
				}
				else {
					Rin[Rinnum].erase(i-1, 2);
					i = i - 2;
				}
			}
		}
	}
	int num = 0;
	for(int i=0; i<modelnum && i<Rinnum; i++){
		for(int t=0; t<model[i].size() && t<Rin[i].size(); t++){
			if(model[i][t] == Rin[i][t]) num++;
		}
	}
	int second;
	cin >> second;
	int ans;
	ans = num * 60. / second + 0.5;
	cout << ans;
    return 0;
}
