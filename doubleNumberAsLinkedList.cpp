// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
// Linked List, Maths, Stack

#include <iostream>
using namespace std;

struct ListNode { 
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		void flipList(ListNode* &head) {
			ListNode* prev = NULL;
			ListNode* next;
			while (head) {
				next = head->next;
				head->next = prev;
				prev = head;
				head = next;
			}
			head = prev;
		}
		ListNode* doubleIt(ListNode* head) {
			flipList(head);
			cout << head->val << endl;
			bool carryOne = false;
			ListNode* h = head;
			ListNode* prev;
			while (head) {
				head->val *= 2;
				if (carryOne) {
					head->val++;
					carryOne = false;
				}
				if (head->val >= 10) {
					head->val -= 10;
					carryOne = true;
				}
				prev = head;
				head = head->next;
			}
			if (carryOne) {
				ListNode* last = new ListNode(1);
				prev->next = last;
			}
			flipList(h);
			return h;
		}
};

int main() { 
	Solution solution;
}
