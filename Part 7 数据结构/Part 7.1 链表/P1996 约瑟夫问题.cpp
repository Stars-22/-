#include <bits/stdc++.h>
using namespace std;
/* ����ڵ�ṹ�� */
struct ListNode {
    int val;         // �ڵ�ֵ
    ListNode *next;  // ָ����һ�ڵ��ָ��
    ListNode(int x) : val(x), next() {}  // ���캯��
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
