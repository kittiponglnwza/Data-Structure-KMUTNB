#include <iostream>
using namespace std;

class Queue {
	public:
	    int front = 0;
	    int rear = -1;
	    int arr[100];
	    int size = 0; 
	
	    void enqueue(int x) {
	        if (rear == 100) {
	            cout << "Queue is full" << endl;
	            return;
	        }
	        arr[++rear] = x;
	        size++; 
	    }
	
	    void dequeue() {
	        if (front > rear) {
	            cout << "-1" << endl; 
	            return;
	        }
	        cout << arr[front++] << endl;
	        size--; 
	    }
	
	    void display() {
	        if (front > rear) { 
	            cout << endl;
	            return;
	        }
	        for (int i = front; i <= rear; i++) {
	            cout << arr[i] << " ";
	        }
	        cout << endl;
	    }
	
	    void fal() {
	        if (front > rear) {
	            cout << "-1" << endl;
	            return;
	        } else {
	            cout << arr[front] << " " << arr[rear] << endl;
	        }
	    }
	
	    int Size() {
	        return size;
	    }
};

int main() {
    Queue *q = new Queue();
    int num;
    char input;

    while (true) {
        cin >> input;
        if (input == 'E' || input == 'e') {
            cin >> num;
            q->enqueue(num);
        } else if (input == 'D' || input == 'd') {
            q->dequeue();
        } else if (input == 'P' || input == 'p') {
            q->display();
        } else if (input == 'N' || input == 'n') {
            cout << q->Size() << endl;
        } else if (input == 'S' || input == 's') {
            q->fal();
        } else if (input == 'X' || input == 'x') {
            break;
        }
    }
    delete q;
    return 0;
}


