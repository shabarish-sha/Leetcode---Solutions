 void inorder(struct TreeNode* root,int* res, int* index)
 {
    if(root==NULL)
    return;
    inorder(root->left,res,index);
    res[(*index)++]=root->val;
    inorder(root->right,res,index);
 }
 
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res=(int*)malloc(100*sizeof(int));
    *returnSize=0;
    inorder(root,res,returnSize);
    return res;
}
