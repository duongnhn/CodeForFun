// https://leetcode.com/problems/linked-list-cycle-ii/
// 142. Linked List Cycle II
// Medium

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* fast_pointer = head;
    ListNode* slow_pointer = head;
    bool is_cycle = false;
    while (fast_pointer) {
      fast_pointer = fast_pointer->next;
      if (fast_pointer) {
        fast_pointer = fast_pointer->next;
        slow_pointer = slow_pointer->next;
        if (slow_pointer == fast_pointer) {
          is_cycle = true;
          break;
        }
      }
    }
    if (!is_cycle) return {};
    ListNode* target = head;
    while (target != slow_pointer) {
      target = target->next;
      slow_pointer = slow_pointer->next;
    }
    return target;
  }
};