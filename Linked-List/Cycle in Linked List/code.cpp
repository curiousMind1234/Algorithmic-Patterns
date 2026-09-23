bool hasCycle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

Time  = O(N)
Space = O(1)

How to find the cycle start

After detecting the meeting:

Keep slow at the meeting point.
Set another pointer entry = head.
Move both one step at a time.
The node where they meet is the cycle's starting node.
 ```   
entry = head
slow  = meeting point

while (entry != slow):
    entry = entry->next
    slow = slow->next

return entry
```

Complete code:

Node* detectCycleStart(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect whether a cycle exists
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find the starting node of the cycle
            Node* entry = head;

            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }

            return entry;
        }
    }

    // No cycle
    return nullptr;
}
