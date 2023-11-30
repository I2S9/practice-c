struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL || q == NULL) return (p == q);
    
    // Otherwise, the values should be equal at each node level
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
