int j=0;
void insert(struct TreeNode*t,int*a)
{
  if(t!=NULL){
    a[j++]=t->val;
    insert(t->left,a);
    insert(t->right,a);
  }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int k=0,*p;
    p = malloc(101*sizeof(int));
    insert(root,p);
    *returnSize=j;
    j=k;
    return p;
}
