/*TLE³¬Ê± 
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node *next;
	Node *last;
	Node(int x) : val(x), last(), next() {};
	Node(int x, Node *y, Node *z) : val(x), last(y), next(z) {
		this->last->next = this;
		this->next->last = this;
	}
	~Node(){
		this->last->next = this->next;
		this->next->last = this->last;
	}
};

int main(){
	int n;
	cin >> n;
	Node *head = new Node(0);
	Node *last = new Node(0);
	Node *now = new Node(1, head, last);
	head->next = now;
	last->last = now;
	for(int i=2; i<=n; i++){
		int k, p;
		cin >> k >> p;
		now = head->next;
		while(now != last){
			if(now->val == k){
				if(p){
					now = new Node(i, now, now->next);
				}
				else{
					now = new Node(i, now->last, now);
				}
				break;
			}
			now = now->next;
		}
	}
	int m;
	cin >> m;
	for(int i=1; i<=m; i++){
		int x;
		cin >> x;
		now = head->next;
		while(now != last){
			if(now->val == x){
				delete now;
				break;
			}
			now = now->next;
		}
	}
	now = head->next;
	while(now != last){
		cout << now->val << ' ';
		now = now->next;
	}
	return 0; 
}
*/
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int l, r;
	Node() : l(0), r(0) {}
} a[100010];

int main(){
	a[0].r = 1;
	int n, m, now;
	int k, p, x;
	cin >> n;
	for(int i=2; i<=n; i++){
		cin >> k >> p;
		if(p){
			a[i].l = k;
			a[i].r = a[k].r;
			a[a[k].r].l = i;
			a[k].r = i;
		}
		else{
			a[i].r = k;
			a[i].l = a[k].l;
			a[a[k].l].r = i;
			a[k].l = i;
		}
	}
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> x;
		if(a[x].l == 0 && a[x].r ==0)
			continue;
		a[a[x].l].r = a[x].r;
		a[a[x].r].l = a[x].l;
		a[x].r = 0;
		a[x].l = 0;
	}
	now = a[0].r;
	while(now != 0){
		cout << now << ' ';
		now = a[now].r;
	}
	return 0; 
}
