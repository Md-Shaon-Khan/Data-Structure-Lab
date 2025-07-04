#include<bits/stdc++.h>
using namespace std;

#define MAX 100

char stk[MAX];
int top = -1;

void push(char c){
    if(top>=MAX-1){
        cout<<"Overflow"<<endl;
    }
    else{
        stk[++top] = c;
    }
}

char pop(){
    if(top == -1){
        cout<<"Underflow"<<endl;
    }
    else{
        return stk[top--];
    }
}

char peek(){
    if(top==-1){
        cout<<"No elements left"<<endl;
    }else{
        return stk[top];
    }
}

int precedence(char op){
    switch(op){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

void infixToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];


        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))  
        {
            postfix += c;
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {
            while (peek() != '(' && top != -1) {
                postfix += pop();
            }
            if (peek() == '(') pop(); // Remove '(' from stack
        }
        // If operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix += pop();
            }
            push(c);
        }
    }


    while (top != -1) {
        postfix += pop();
    }

    cout << "Postfix Expression: " << postfix << endl;
}

int main() {
    string infix;
    cout << "Enter Infix Expression (e.g., A+B*(C^D-E)): ";
    cin >> infix;
    infixToPostfix(infix);
    return 0;
}