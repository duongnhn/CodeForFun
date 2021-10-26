// https://leetcode.com/problems/merge-two-binary-trees/
// 617. Merge Two Binary Trees
// Easy

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// */
class Solution {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode* t{};
    helper(t, t1, t2);
    return t;
  }

  void helper(TreeNode*& t, TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return;
    t = new TreeNode();
    if (t1 && t2) {
      t->val = t1->val + t2->val;
      helper(t->left, t1->left, t2->left);
      helper(t->right, t1->right, t2->right);
    }
    else if (t1) {
      t->val = t1->val;
      helper(t->left, t1->left, nullptr);
      helper(t->right, t1->right, nullptr);
    }
    else {
      t->val = t2->val;
      helper(t->left, nullptr, t2->left);
      helper(t->right, nullptr, t2->right);
    }
  }
};