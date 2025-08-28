#include<iostream>
using namespace std;

class queue{
public:
    int arr[5];
    int front = 2;
    int rear = 1;
    int size = 5;
    int count = 0;
    
    bool empty(){
        if(count == 0){
            cout << "Queue Empty";
            cout << " " << "f:" << front << " " << "r:" << rear << endl;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool full(){
        if(count == size){
            cout << "Queue Full";
            cout << " " << "f:" << front << " " << "r:" << rear << endl;
            return true;
        }
        else{
            return false;
        }
    }
    
    void enqueue(int data){
        if(!full()){
            rear = (rear + 1) % size;  
            arr[rear] = data;          
            count++;                   
            cout << "f:" << front << " " << "r:" << rear << endl;
        }
    }
    
    void dequeue(){
        if(!empty()){
            int temp = arr[front];     
            cout << temp << " ";       
            front = (front + 1) % size; 
            count--;                   
            cout << "f:" << front << " " << "r:" << rear << endl;
        }
    }
};

int main(){
    queue *q = new queue();
    char text;
    int num;
    
    while(1){
        cin >> text;
        if(text == 'e'){
            cin >> num;
            q->enqueue(num);
        }
        else if(text == 'd'){
            q->dequeue();
        }
        else if(text == 'x'){
            break;
        }
    }
    
    delete q;  
    return 0;
}
