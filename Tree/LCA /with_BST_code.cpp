Node* LCA(Node* root, Node* p, Node* q)
{
    if (root == nullptr)
        return nullptr;

    if (p->data < root->data && q->data < root->data)
        return LCA(root->left, p, q);

    if (p->data > root->data && q->data > root->data)
        return LCA(root->right, p, q);

    return root;
}


Time: O(h)
Space: O(h) for recursive version
