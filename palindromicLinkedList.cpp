/**
 * https://leetcode.com/problems/palindrome-linked-list/
 * Linked List, Two Pointers, Stack, Recursion
 * Easy
 */
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
		bool isPalindrome(ListNode* head) {
			// make reverse of linked list
			ListNode* copy = head;
			ListNode* reverseList = new ListNode;
			reverseList->val = copy->val;
			reverseList->next = nullptr;
			while (copy) {
				ListNode* newNode = new ListNode;
				newNode->val = copy->val;
				newNode->next = reverseList;
				reverseList = newNode;
				copy = copy->next;
			}
			// compare between reverse linked list and original linked list
			while (head && reverseList) {
				if (head->val != reverseList->val) {
					return false;
				}
				head = head->next;
				reverseList = reverseList->next;
			}
			return true;
		}
};

int main() {
	ListNode* head = new ListNode;
	ListNode* curr = head;
	curr->next = new ListNode;
	curr = curr->next;
	ListNode* last;
	int num;
	while (cin >> num && num != -1) {
		curr->val = num;
		curr->next = new ListNode;
		curr = curr->next;
	}
	curr = nullptr;
	/*
	   while (head) {
	   cout << head->val << ' ';
	   head = head->next;
	   }*/
	Solution solution;
	if (solution.isPalindrome(head)) {
		cout << "is palindrome" << endl;
	} else {
		cout << "is not palindrome" << endl;
	}
}
