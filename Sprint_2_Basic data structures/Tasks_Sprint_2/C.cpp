/*
Algorithm Description in Comments
    Handling Special Case for the Head:
        If idx == 0, the function removes the head of the list by updating the head pointer to point to the second node.
        The old head is deleted to free memory.
    Traversing to the Node Before the Target:
        A loop traverses the list to find the node just before the one that needs to be removed.
        If the index exceeds the length of the list (i.e., current->next == nullptr), the function returns the original head without modifying the list.
    Removing the Target Node:
        If the target node exists (current->next != nullptr), it is skipped by updating the next pointer of the preceding node to point to the node after the target.
        The target node is then deleted to free memory.
    Returning the Updated List:
        After modifying the list, the function returns the original head unless it was the node removed (handled in step 1).
        This approach ensures efficient memory management and maintains the structure of the list with a time complexity of O(n), where n is the index of the node to be removed.
*/

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>

// Definition of the structure for a node in a singly linked list
struct Node {  
    std::string value;  // Value of the node
    Node* next;         // Pointer to the next node
    Node(const std::string &value, Node* next) : value(value), next(next) {}
};
#endif

// Function to delete an element from the list by a given index
Node* solution(Node* head, int idx) {
    // If the first element (the head of the list) needs to be removed
    if (idx == 0) {
        Node* new_head = head->next;  // The new head of the list is the next node
        delete head;  // Delete the old head of the list
        return new_head;  // Return the new head of the list
    }
    
    Node* current = head;  // Pointer to the current node, starting from the head of the list
    // Traverse the list to the node preceding the one to be removed
    for (int i = 0; i < idx - 1; ++i) {
        if (current->next == nullptr) return head;  // If the index is out of range, return the head of the list
        current = current->next;  // Move to the next node
    }
    
    // Pointer to the node that needs to be deleted
    Node* node_to_delete = current->next;
    if (node_to_delete != nullptr) {
        current->next = node_to_delete->next;  // Adjust the pointer to skip the node being deleted
        delete node_to_delete;  // Delete the node
    }
    
    return head;  // Return the head of the updated list
}

#ifndef REMOTE_JUDGE
// Test function to verify the solution works correctly
void test() {
    Node node3("node3", nullptr);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node node0("node0", &node1);
    Node* new_head = solution(&node0, 1);  // Remove the node at index 1 (node1)
    assert(new_head == &node0);  // Ensure the head of the list remains unchanged
    assert(new_head->next == &node2);  // Ensure node0 now points to node2
    assert(new_head->next->next == &node3);  // Ensure node2 points to node3
    assert(new_head->next->next->next == nullptr);  // Ensure node3 is the last node
    // Resulting list: node0 -> node2 -> node3
}

int main() {
    test();  // Call the test function
}
#endif
