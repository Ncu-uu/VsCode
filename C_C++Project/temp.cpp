#include <iostream>
#include <cstring>

using namespace std;

// Define the node structure for the linked list
struct Node {
    char data;
    Node* next;
};

// Define the stack structure
struct Stack {
    Node* top;
    int size;
};

// Initialize an empty stack
void init(Stack& s) {
    s.top = NULL;
    s.size = 0;
}

// Check if the stack is empty
bool isEmpty(Stack& s) {
    return s.top == NULL;
}

// Push an element onto the stack
void push(Stack& s, char c) {
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = s.top;
    s.top = newNode;
    s.size++;
}

// Pop an element from the stack
char pop(Stack& s) {
    if (isEmpty(s)) {
        return '\0';
    }
    char c = s.top->data;
    Node* temp = s.top;
    s.top = s.top->next;
    delete temp;
    s.size--;
    return c;
}

// Peek at the top element of the stack
char peek(Stack& s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s.top->data;
}

// Check if two parentheses match
bool match(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

// Check if a string of parentheses is balanced
bool isBalanced(char* str) {
    Stack s;
    init(s);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(s, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (isEmpty(s) || !match(pop(s), str[i])) {
                return false;
            }
        }
    }
    return isEmpty(s);
}

int main() {
    char str[100];
    cout << "Enter a string of parentheses: ";
    cin >> str;
    if (isBalanced(str)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }
    return 0;
}
