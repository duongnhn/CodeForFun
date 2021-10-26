// https://leetcode.com/problems/palindrome-linked-list/
// 234. Palindrome Linked List
// Easy

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  // Find middle node then reverse from middle node and compare with head.
  bool isPalindrome(ListNode* head) {
    ListNode* fast_pointer = head;
    ListNode* slow_pointer = head;
    while (fast_pointer) {
      fast_pointer = fast_pointer->next;
      slow_pointer = slow_pointer->next;
      if (fast_pointer) {
        fast_pointer = fast_pointer->next;
      }
    }
    ListNode* start = head;
    ListNode* end = reverse(slow_pointer);
    while (end && start) {
      if (start->val != end->val) return false;
      start = start->next;
      end = end->next;
    }
    return true;
  }

  ListNode* reverse(ListNode* head) {
    ListNode* preNode = nullptr;
    while (head) {
      auto nextNode = head->next;
      head->next = preNode;
      preNode = head;
      head = nextNode;
    }
    return preNode;
  }
};
