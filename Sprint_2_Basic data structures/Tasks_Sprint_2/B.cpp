#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <string>

#ifndef REMOTE_JUDGE

// Definition of the structure for a node in a singly linked list
struct Node {
    std::string value;  // The value of the node
    Node* next;         // Pointer to the next node in the list
    Node(const std::string &value, Node* next) : value(value), next(next) {}
};

/*
Explanation

Code Overview:
    This code defines a singly linked list structure and a function solution that prints all elements in the list.
    A test setup is provided under the #ifndef REMOTE_JUDGE block to verify the implementation.
    
Key Components:
    Node Structure:
    The Node struct represents a node in a singly linked list. Each node contains:
        A value of type std::string.
        A pointer next pointing to the next node in the list (or nullptr if it is the last node).
        A constructor to initialize the value and next fields.
    solution Function:
    This function:
        Starts with the head of the list and traverses each node.
        Prints the value of the current node.
        Advances to the next node using the next pointer.
        Stops when it encounters a nullptr, indicating the end of the list.
    Test Function:
        A linked list with four nodes is created.
        The solution function is tested by passing the head of the list.
        The expected output is printed to validate correctness.
    Preprocessor Directives:
        The #ifdef REMOTE_JUDGE block ensures that certain parts of the code (like Node definition) are only included during local testing and excluded in the online judge environment.

This code demonstrates how to define and traverse a singly linked list using a simple iterative approach. It uses preprocessor directives to separate local testing and online submission contexts. The test case verifies that the solution function works correctly.

*/

#endif

// Function to print all elements in the linked list
void solution(Node* head) {
    Node* current = head;  // Pointer to the current node, starting from the head of the list
    while (current != nullptr) {  // Traverse the list until reaching the end (nullptr)
        std::cout << current->value << std::endl;  // Print the value of the current node
        current = current->next;  // Move to the next node
    }
}

#ifndef REMOTE_JUDGE

// Test function to verify the correctness of the solution function
void test() {
    Node node3("node3", nullptr);  // Create the last node (next pointer is nullptr)
    Node node2("node2", &node3);   // Create a node pointing to node3
    Node node1("node1", &node2);   // Create a node pointing to node2
    Node node0("node0", &node1);   // Create a node pointing to node1 (head of the list)
    solution(&node0);  // Call the solution function, passing a pointer to the head of the list
    /*
    Expected output:
    node0
    node1
    node2
    node3
    */
}

int main() {
    test();  // Call the test function
}

#endif