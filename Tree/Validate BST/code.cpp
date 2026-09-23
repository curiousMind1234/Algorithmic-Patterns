bool isValidBST(Node* root, long long minVal, long long maxVal)
{
    if (root == nullptr)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
}

Call it:
bool result = isValidBST(root, LLONG_MIN, LLONG_MAX);
----------------------------------------------------
Time: O(n) in the worst case, not O(h).
Space: O(h) due to the recursion stack.

  
  
Simple dry run

Tree:

        8
       / \
      3   10
         /
        6

Start:

isValidBST(8, -∞, +∞)

8 is valid → check left and right.

Left:

isValidBST(3, -∞, 8)

3 is between -∞ and 8 → valid.

Its children are NULL:

isValidBST(NULL, -∞, 3) → true
isValidBST(NULL, 3, 8)   → true

So node 3 → true.

Right:

isValidBST(10, 8, +∞)

10 is valid.

Now its left child:

isValidBST(6, 8, 10)

But 6 is not between 8 and 10.

Therefore:

6 <= 8 → true

So:

isValidBST(6, 8, 10) → false

Finally:

left  = true
right = false

true && false = false

So the tree is not a valid BST.

Remember

For every node:

Left subtree  → (-∞, node)
Right subtree → (node, +∞)

and as we go down, the range becomes narrower.
