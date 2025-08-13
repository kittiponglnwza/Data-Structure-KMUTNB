#include <iostream>
#include <string.h>

using namespace std;

class stack {
public:
    char arr[100];
    int top = -1;

    void push(char x) {
        if (top >= 99) {
            cout << "stack overflow" << endl;
        } else {
            ++top;
            arr[top] = x;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "stack underflow" << endl;
        } else {
            top--;
        }
    }
};

int main() {
    stack* st = new stack;
    char a[100];
    
    cin.getline(a, 100);
    
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '(') {
            st->push('(');
        } 
        else if (a[i] == ')') {
            if (st->top >= 0 && st->arr[st->top] == '(') {
                st->pop();
            } else {
                cout << "Error" << endl;
                return 0;
            }
        }
    }

    if (st->top == -1) {
        cout << "pass" << endl;
    } else {
        cout << "error" << endl;
    }

    return 0;
}

