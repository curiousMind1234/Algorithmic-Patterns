bool searchBST(Node* root, int target)
{
    if (root == nullptr)
        return false;

    if (root->data == target)
        return true;

    if (target < root->data)
        return searchBST(root->left, target);
    else
        return searchBST(root->right, target);
}

Time: O(h), where h is tree height.
Space: O(h) due to recursion.
