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
    int num;
    cout << "Input Linked List: " << endl;
    while (cin >> num && num != -1) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    ListNode* newHead = head->next;
    delete head;
	/*
	   while (newHead) {
	   cout << newHead->val << ' ';
	   newHead = newHead->next;
	   }*/
	Solution solution;
	if (solution.isPalindrome(newHead)) {
		cout << "is palindrome" << endl;
	} else {
		cout << "is not palindrome" << endl;
	}
}