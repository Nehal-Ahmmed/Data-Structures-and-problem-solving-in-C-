#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *next;
};

struct Stack {
    Node *top;
    int count;
};

Stack* createStack() {
    Stack *st = new Stack();
    st->top = NULL;
    st->count = 0;
    return st;
}

void push(Stack *st, char data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = st->top;
    st->top = newNode;
    st->count++;
}

char pop(Stack *st) {
    if (st->top == NULL) return '#';
    
    Node *temp = st->top;
    char data = temp->data;
    st->top = st->top->next;
    
    delete temp;
    st->count--;
    return data;
}

char peek(Stack *st) {
    if (st->top == NULL) return '#';
    return st->top->data;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    Stack *st = createStack();
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }
        else if (c == '(') {
            push(st, c);
        }
        else if (c == ')') {
            while (st->top != NULL && peek(st) != '(') {
                postfix += pop(st);
            }
            pop(st);
        }
        else if (isOperator(c)) {
            while (st->top != NULL && precedence(peek(st)) >= precedence(c)) {
                postfix += pop(st);
            }
            push(st, c);
        }
    }
    
    while (st->top != NULL) {
        postfix += pop(st);
    }
    
    return postfix;
}

int evaluatePostfix(string postfix) {
    Stack *st = createStack();
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (c >= '0' && c <= '9') {
            push(st, c);
        }
        else if (isOperator(c)) {
            int val2 = pop(st) - '0';
            int val1 = pop(st) - '0';
            int result;
            
            if (c == '+') result = val1 + val2;
            else if (c == '-') result = val1 - val2;
            else if (c == '*') result = val1 * val2;
            else if (c == '/') result = val1 / val2;
            else if (c == '^') result = pow(val1, val2);
            else result = 0;
            
            push(st, result + '0');
        }
    }
    
    return pop(st) - '0';
}

int main() {
    string infix;
    int choice;
    
    cout << "Infix to Postfix Converter" << endl;
    cout << "1. Convert only" << endl;
    cout << "2. Convert and evaluate" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    
    if (choice == 1) {
        cout << "Enter infix expression: ";
        cin >> infix;
        
        string postfix = infixToPostfix(infix);
        cout << "Infix: " << infix << endl;
        cout << "Postfix: " << postfix << endl;
    }
    else if (choice == 2) {
        cout << "Enter infix expression (numbers only): ";
        cin >> infix;
        
        string postfix = infixToPostfix(infix);
        int result = evaluatePostfix(postfix);
        
        cout << "Infix: " << infix << endl;
        cout << "Postfix: " << postfix << endl;
        cout << "Result: " << result << endl;
    }
    
    return 0;
}