#include <iostream>
#include <string.h>
using namespace std;

class stack {
public:
    char arr[100];
    int top = -1;

    void push(char x) {
        if (top >= 99) {
            cout << "stack is overflow" << endl;
        } else {
            ++top;
            arr[top] = x;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "stack is underflow" << endl;
        } else {
            top--;
        }
    }

    char peek() {
        if (top >= 0) return arr[top];
        return '\0';
    }

    bool empty() {
        return top < 0;
    }
};

bool isOpening(char c) {
    return c == '(' || c == '[' || c == '{' || c == '<';
}

bool isClosing(char c) {
    return c == ')' || c == ']' || c == '}' || c == '>';
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

int main() {
    stack *st = new stack;
    char a[200]; 
    cin.getline(a, 200);

    int matchedCount = 0;

    for (int i = 0; i < strlen(a); i++) {
        char c = a[i];

        
        if ((c == '<' && a[i+1] == '<') || (c == '>' && a[i+1] == '>')) {
            i++; 
            continue;
        }

        if (isOpening(c)) {
            st->push(c);
        } 
        
		else if (isClosing(c)) {
			
            if (!st->empty() && isMatching(st->peek(), c)) {
                st->pop();
                matchedCount++;
            } else {
                cout << "Not matched" << endl;
                cout << matchedCount << " matched" << endl;
            }
        }
    }

    if (st->empty()) {
        cout << matchedCount << " matched" << endl;
    } else {
        cout << "Not matched" << endl;
        cout << matchedCount << " matched" << endl;
    }

    return 0;
}

