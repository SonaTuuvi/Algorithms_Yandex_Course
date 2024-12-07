/*
To evaluate the value of an expression written in Reverse Polish Notation (RPN), I use a stack. Here are the main reasons why I chose to use a stack:

- In Reverse Polish Notation, operands come before operators. This means I can sequentially process the tokens of the expression, pushing operands onto the stack and applying operators to the most recently added operands.
- A stack supports both the addition of elements (push) and the removal of elements (pop) in O(1) time. This is ideal for the operations needed to read and evaluate an expression in Reverse Polish Notation.
- While reading the expression, I push numbers (operands) onto the stack. This makes it easy to retrieve the most recently added operands when an operator is encountered.
- A stack is suitable for handling nested operations in the expression.

**Algorithm Complexity**

The algorithm for evaluating the value of an expression written in Reverse Polish Notation (RPN) has a time complexity of O(n), where \( n \) is the number of tokens in the expression.

1. **Reading the Expression:**  
   Since each token of the expression is read sequentially once, and the number of tokens is \( n \), this takes O(n) time.

2. **Initializing an Empty Stack:**  
   Initializing the stack takes O(1) time.

3. **Processing Each Token:**  
   For each token, one of two operations is performed:  
   - If the token is a number, it is pushed onto the stack (push operation), which takes O(1) time.  
   - If the token is an operator, one or two operands (depending on the operator) are popped from the stack, the operation is performed, and the result is pushed back onto the stack. These operations also take O(1) time.  
   Since each token is processed exactly once, and each operation takes O(1) time, the total complexity for processing all tokens is O(n).

**Conclusion:**  
The overall time complexity of the algorithm is O(n).

**Space Complexity:**  
The space complexity of the algorithm also depends on the number of tokens in the expression. In the worst case (when all tokens are operands, such as numbers), we need to store all \( n \) elements in the stack, requiring O(n) memory. Thus, the space complexity of the algorithm is also O(n).

**Algorithm Steps:**  
1. Read the expression in Reverse Polish Notation.  
2. Initialize an empty stack.  
3. For each token in the expression:  
   - If the token is a number, push it onto the stack.  
   - If the token is an operator, pop the required number of operands from the stack, perform the operation, and push the result back onto the stack.  
4. After processing all tokens, the result of the computation will be at the top of the stack.

**Example:**  
For the expression `2 1 + 3 *`:

Steps:  
- `2` → [2]  
- `1` → [2, 1]  
- `+` → [3] (2 + 1 = 3)  
- `3` → [3, 3]  
- `*` → [9] (3 * 3 = 9)  
Result: 9
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;

// Function to evaluate Reverse Polish Notation expressions
int evaluateRPN(vector<string>& tokens) {
    stack<int> stack;

    for (const string& token : tokens) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            // If the token is a number, push it onto the stack
            stack.push(stoi(token));
        } else {
            // The token is an operator
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (token == "+") {
                stack.push(operand1 + operand2);
            } else if (token == "-") {
                stack.push(operand1 - operand2);
            } else if (token == "*") {
                stack.push(operand1 * operand2);
            } else if (token == "/") {
                // Division with truncation
                if (operand2 != 0) {
                    stack.push(floor((double)operand1 / operand2));
                } else {
                    cout << "Error: Division by zero" << endl;
                    return INT_MIN; // Return a special value to indicate an error
                }
            }
        }
    }

    // The result of the computation is at the top of the stack
    return stack.top();
}

int main() {
    string input;
    getline(cin, input); // Read the expression as a single line

    vector<string> tokens;

    // Split the input string into tokens
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        string token = input.substr(0, pos);
        tokens.push_back(token);
        input.erase(0, pos + 1);
    }
    tokens.push_back(input); // Add the last token

    // Compute and output the result
    int result = evaluateRPN(tokens);
    if (result != INT_MIN) {
        cout << result << endl;
    }

    return 0;
}
