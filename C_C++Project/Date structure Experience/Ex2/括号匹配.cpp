#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) {
        return '\0';
    }
    char data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}

bool isMatchingPair(char left, char right) {
    if (left == '(' && right == ')') {
        return true;
    } else if (left == '[' && right == ']') {
        return true;
    } else if (left == '{' && right == '}') {
        return true;
    } else {
        return false;
    }
}

bool isBalanced(char* exp) {
    Node* top = nullptr;
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(top, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (top == nullptr) {
                return false;
            } else if (!isMatchingPair(pop(top), exp[i])) {
                return false;
            }
        }
    }
    if (top == nullptr) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char exp[100];
    cout << "Enter an expression: ";
    cin >> exp;
    if (isBalanced(exp)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }
    return 0;
}
