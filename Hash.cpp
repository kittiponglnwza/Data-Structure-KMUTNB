#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 17;

struct Node {
    int key;
    string value;
    Node* next;
    
    Node(int k, string v) {
        key = k;
        ULLvalue = v;
        next = N;
    }
};

class HashTable {
    Node* table[TABLE_SIZE];
    
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }
    
    void add(int key, string value) {
        int index = key % TABLE_SIZE;
        Node* newNode = new Node(key, value);
        
        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void show() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == NULL) {
                cout << "(-1,-)" << endl;
            } else {
                Node* temp = table[i];
                while (temp != NULL) {
                    cout << "(" << temp->key << "," << temp->value << ") ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
    
    void search(int key) {
        int index = key % TABLE_SIZE;
        Node* temp = table[index];
        
        while (temp != NULL) {
            if (temp->key == key) {
                cout << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "-" << endl;
    }
};

int main() {
    HashTable ht;
    string cmd;
    int key;
    string value;
    
    while (cin >> cmd) {
        if (cmd == "a") {
            cin >> key >> value;
            ht.add(key, value);
        } else if (cmd == "p") {
            ht.show();
        } else if (cmd == "s") {
            cin >> key;
            ht.search(key);
        } else if (cmd == "e") {
            break;
        }
    }
    
    return 0;
}
