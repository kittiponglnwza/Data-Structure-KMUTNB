#include<iostream>
#include<string>
using namespace std;

class stack{
public:
    string arr[50];
    int top = -1;
    
    bool empty(){
        if(top==-1){
            return true;
        } else{
            return false;
        }
    }
    
    bool full(){
        if(top>=49){
            return true;
        } else{
            return false;
        }
    }
    
    void push(string data){
        if(!full()){
            top++;
            arr[top] = data;
        }
    }
    
    string pop(){
        if(!empty()){
            string temp = arr[top];
            top--;
            return temp;
        }
        return "";
    }
    
    void clear(){
        top = -1;
    }
    
    void print(){
        cout<<"text : ";
        for(int i=0;i<=top;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
};

int main(){
    stack *undo = new stack();
    stack *redo = new stack();
    string currentText = "";
    char text;
    string t;
    
    cout << "text : " << endl; 
    
    while(1){
        cin>>text;
        if(text=='i'){
            cin.ignore();
            getline(cin,t);
            
            undo->push(currentText); 
            currentText += t;       
            redo->clear();          
            
            cout << "text : " << currentText << endl;
        }
        else if(text=='u'){
            if(!undo->empty()){
                redo->push(currentText);           
                currentText = undo->pop();         
                cout << "text : " << currentText << endl;
            } else {
                cout << "Nothing to undo" << endl;
            }
        }
        else if(text=='r'){
            if(!redo->empty()){
                undo->push(currentText);           
                currentText = redo->pop();         
                cout << "text : " << currentText << endl;
            } else {
                cout << "Nothing to redo" << endl;
            }
        }
        else if(text=='q'){
            break;
        }
    }
}
