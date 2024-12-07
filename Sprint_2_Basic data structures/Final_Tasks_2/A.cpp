/*
 
To implement an efficient deque data structure using a circular buffer, where the operations push_back(x), push_front(x), pop_back(), and pop_front() are performed in O(1) time, I used the following:

**Principles of Operation and Choice of Implementation**  
- Use of a circular buffer.  
- Two indices to manage the deque.  
- Optimization of pop_back() and pop_front() operations.  
- Time and space complexity considerations.

**Proof of Correctness**

*Use of a Circular Buffer:*  
The circular buffer ensures constant-time operations for adding and removing elements because elements are only added to or removed from the ends of the data structure.  
In this implementation, a fixed-size array is used to store deque elements. This avoids dynamic memory allocation and deallocation, significantly improving performance and reducing the risk of memory leaks.  

*Use of Two Indices to Manage the Deque:*  
- **front_index**: Index of the front of the deque.  
- **back_index**: Index of the back of the deque (the position after the last element).  
- When adding an element to the front of the deque, **front_index** is decremented.  
- When adding an element to the back of the deque, **back_index** is incremented.  

*Error Handling for Overflow:*  
- If the deque already contains the maximum number of elements, any addition operation (push_back or push_front) should output the message `"error"`.  
- Attempting to remove an element from an empty deque (pop_front or pop_back) should also output the message `"error"`.  

*Optimization of pop_back and pop_front Operations:*  
- Removing an element from the back of the deque (pop_back) is done in constant time by updating **back_index**.  
- Removing an element from the front of the deque (pop_front) is also done in constant time by incrementing **front_index**.  

**Time and Space Complexity**

*Time Complexity:*  
Each of the operations `push_back`, `push_front`, `pop_back`, and `pop_front` is performed in O(1) time because they involve simple arithmetic operations and direct access to array elements.  

**Initialization:**  
The initialization of the circular buffer involves creating a fixed-size array and setting the initial values of the front and back indices. Array initialization takes O(n) time, where n is the size of the buffer.  

**Overall Complexity:**  
- `push_back(x)`: Add an element to the back of the deque.  
- `push_front(x)`: Add an element to the front of the deque.  
- `pop_back()`: Remove an element from the back of the deque.  
- `pop_front()`: Remove an element from the front of the deque.  

All of these operations are O(1) due to the use of simple arithmetic operations and direct array accesses.  

**Space Complexity:**  
The space complexity depends on the size of the buffer. If the buffer size is fixed and equal to m, the space complexity is O(m). If the buffer size is dynamic (e.g., using a doubling strategy when the buffer overflows), additional space is required for the new buffer and copying data, temporarily increasing memory usage. However, the amortized space complexity remains O(n).  
*/

#include <iostream>
#include <vector>
using namespace std;

class CircularDeque {
private:
    vector<int> buffer;     // Vector to store deque elements
    int max_size;           // Maximum size of the deque
    int front_index;        // Index of the front of the deque
    int back_index;         // Index of the back of the deque
    int current_size;       // Current size of the deque

public:
    CircularDeque(int m)
        : max_size(m)
        , front_index(0)
        , back_index(0)
        , current_size(0)
        , buffer(m)  // Initialize buffer with size m
    {
    }

    void push_back(int value) {
        if (current_size == max_size) {     // Check for deque overflow
            cout << "error" << endl;        // Output error message
            return;                         // Exit the function
        }
        buffer[back_index] = value;         // Add the element to the back of the deque
        back_index = (back_index + 1) % max_size;   // Update back index with circular buffer logic
        ++current_size;                     // Increase the current size of the deque
    }

    void push_front(int value) {
        if (current_size == max_size) {     // Check for deque overflow
            cout << "error" << endl;        // Output error message
            return;                         // Exit the function
        }
        front_index = (front_index - 1 + max_size) % max_size;   // Update front index with circular buffer logic
        buffer[front_index] = value;        // Add the element to the front of the deque
        ++current_size;                     // Increase the current size of the deque
    }

    void pop_back() {
        if (current_size == 0) {            // Check if the deque is empty
            cout << "error" << endl;        // Output error message
            return;                         // Exit the function
        }
        back_index = (back_index - 1 + max_size) % max_size;   // Update back index with circular buffer logic
        cout << buffer[back_index] << endl; // Output and remove the element from the back of the deque
        --current_size;                     // Decrease the current size of the deque
    }

    void pop_front() {
        if (current_size == 0) {            // Check if the deque is empty
            cout << "error" << endl;        // Output error message
            return;                         // Exit the function
        }
        cout << buffer[front_index] << endl; // Output and remove the element from the front of the deque
        front_index = (front_index + 1) % max_size;   // Update front index with circular buffer logic
        --current_size;                     // Decrease the current size of the deque
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    CircularDeque deque(m);     // Create a deque with a maximum size of m

    string command;
    int value;

    for (int i = 0; i < n; ++i) {
        cin >> command;         // Read the command
        if (command == "push_back") {
            cin >> value;       // Read the value for push_back
            deque.push_back(value); // Call the deque's push_back method
        } else if (command == "push_front") {
            cin >> value;       // Read the value for push_front
            deque.push_front(value);    // Call the deque's push_front method
        } else if (command == "pop_back") {
            deque.pop_back();   // Call the deque's pop_back method
        } else if (command == "pop_front") {
            deque.pop_front();  // Call the deque's pop_front method
        }
    }

    return 0;
}