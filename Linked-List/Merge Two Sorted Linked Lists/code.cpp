Node* mergeList(Node* list1, Node* list2) {

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (list1 != NULL && list2 != NULL) {

        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    // Attach remaining nodes
    if (list1 != NULL) {
        tail->next = list1;
    }
    else {
        tail->next = list2;
    }

    return dummy->next;
}

Time: O(N + M)
Space: O(1) auxiliary space.

