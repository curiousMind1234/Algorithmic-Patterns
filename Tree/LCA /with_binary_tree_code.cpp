TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL) return NULL;
    if(root == p || root == q) return root;

    TreeNode* leftR = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightR = lowestCommonAncestor(root->right, p,q);

    if(leftR && rightR) return root;
    else if(leftR) return leftR;
    else {
        return rightR;
    }
}

TC: O(N)
SC: O(h)
