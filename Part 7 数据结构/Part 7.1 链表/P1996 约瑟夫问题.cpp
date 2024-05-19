#include <bits/stdc++.h>
using namespace std;
/* 链表节点结构体 */
struct ListNode {
    int val;         // 节点值
    ListNode *next;  // 指向下一节点的指针
    ListNode(int x) : val(x), next() {}  // 构造函数
};

int main(){
	int n, m;
	cin >> n >> m;
	ListNode *gen = new ListNode(1);
	ListNode *last = gen;
	for(int i=2; i<=n; i++){
		ListNode *next = new ListNode(i);
		last->next = next;
		last = next;
	}
	last->next = gen;
	ListNode *now = gen;
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			last = now;
			now = now->next;
		}
		last->next = now->next;
		cout << now->val << ' ';
		delete now;
		now = last->next;
	}
	cout << now->val;
	return 0;
}
