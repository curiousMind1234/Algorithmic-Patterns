Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;  // save next node
        curr->next = prev;  // reverse link
        prev = curr;        // move prev
        curr = next;        // move curr
    }

    return prev;
}

Time  = O(N)
Space = O(1)


1. Save next
2. Reverse current link
3. Move prev
4. Move curr
