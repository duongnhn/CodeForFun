// https://leetcode.com/problems/design-linked-list/
// 707. Design Linked List
// Medium

struct Node {
  int val = -1;
  Node* next = nullptr;
};

class MyLinkedList {
  Node* head;
  int size = 0;

  Node* getNode(int index) {
    if (index == -1) return head;
    if (index >= size || index < 0) return nullptr;
    Node* target = head;
    while (index >= 0) {
      target = target->next;
      index--;
    }
    return target;
  }
public:
  /** Initialize your data structure here. */
  MyLinkedList() {
    this->head = new Node(); // head is a dummy node.
  }

  /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
  int get(int index) {
    if (index >= size || index < 0) return -1;
    Node* target = getNode(index);
    return target->val;
  }

  /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    Node* new_node = new Node();
    new_node->val = val;
    new_node->next = head->next;
    head->next = new_node;
    size++;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    Node* tail = getNode(size-1);
    Node* new_tail = new Node();
    new_tail->val = val;
    tail->next = new_tail;
    size++;
  }

  /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
  void addAtIndex(int index, int val) {
    if (index > size || index < 0) return;
    if (index == size) return addAtTail(val);
    Node* node_before_index_th = getNode(index-1);

    Node* new_node = new Node();
    new_node->val = val;

    new_node->next = node_before_index_th->next;
    node_before_index_th->next = new_node;
    size++;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index >= size || index < 0) return;
    Node* node_before_index = getNode(index - 1);
    Node* node_index = node_before_index->next;
    node_before_index->next = node_before_index->next->next;
    size--;
    delete(node_index);
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */