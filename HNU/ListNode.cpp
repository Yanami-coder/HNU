#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	explicit ListNode(int v = 0, ListNode* n = nullptr) :val(v), next(n) {}
};

static ListNode* mergeTwo(ListNode* a, ListNode* b) {
	ListNode dummy;
	ListNode* tail = &dummy;
	while (a && b) {
		if (a->val <= b->val) {
			tail->next = a;
			a = a->next;
		}
		else {
			tail->next = b;
			b = b->next;
		}
		tail = tail->next;
	}
	tail->next = a ? a : b;
	return dummy.next;
}

static ListNode* mergeSort(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* mid = slow->next;
	slow->next = nullptr;
	return mergeTwo(mergeSort(head), mergeSort(mid));
}

// 创建一个链表，返回头指针
ListNode* createList(const vector<int>& vals) {
	ListNode* head = nullptr;
	ListNode** pp = &head;
	for (int v : vals) {
		*pp = new ListNode(v);
		pp = &(*pp)->next;
	}
	return head;
}

// 在第i个节点后插入一个值为v的节点，返回是否成功
bool insertAfter(ListNode*& head, int i, int v) {
	if (i < 0) return false;
	ListNode** pp = &head;
	int k = 0;
	while (k < i && *pp) {
		pp = &(*pp)->next;
		++k;
	}
	if (k < i) return false;
	*pp = new ListNode(v, *pp);
	return true;
}

// 删除第i个节点，返回是否成功
bool removeAt(ListNode*& head, int i) {
	if (i < 1) return false;
	ListNode** pp = &head;
	int k = 1;
	while (k < i && *pp) {
		pp = &(*pp)->next;
		++k;
	}
	if (!*pp) return false;
	ListNode* del = *pp;
	*pp = del->next;
	delete del;
	return true;
}

// 查找值为x的节点，返回其位置(从1开始)，若不存在则返回-1
int findNode(ListNode* head, int x) {
	int idx = 1;
	for (ListNode* p = head;p;p = p->next, ++idx)
		if (p->val == x) return idx;
	return -1;
}

// 对链表进行排序
void sortList(ListNode*& head) {
	head = mergeSort(head);
}

// 销毁链表
void destroyList(ListNode*& head) {
	while (head) {
		ListNode* n = head->next;
		delete head;
		head = n;
	}
}

// 读取输入的整数，返回一个vector
vector<int> readInput() {
	string line;
	getline(cin, line);
	istringstream iss(line);
	vector<int> vals;
	int x;
	while (iss >> x) vals.push_back(x);
	return vals;
}

// 打印链表
void printList(ListNode* head) {
	cout << "[";
	for (ListNode* p = head;p;p = p->next) {
		cout << p->val;
		if (p->next) cout << "->";
	}
	cout << "]\n";
}

int main() {
	cout << "请输入任意个整数(空格分隔),回车结束:\n";
	vector<int> vals = readInput();

	ListNode* head = createList(vals);
	cout << "创建的链表为: "; printList(head);

	sortList(head);
	cout << "排序后的链表为: "; printList(head);

	destroyList(head);
	return 0;
}