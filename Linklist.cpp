#include <iostream>
using namespace std;

class Node{
	public:
		Node *next;
		int value;
	Node(int data){
		value = data;
		next = NULL;
	}
};
class LinkList{
	public:
	Node *head = NULL;
	Node *last = NULL;
	
	
	void insert(int data){
		Node *n = new Node(data);
		if (this->head == NULL){
			this->head = n;
			this->last = this->head;
		} 
		else{
			this->last->next = n;
			this->last = n;
		}
	}
	void insert_before(int data, int id){
		if (search(id)){
			Node *isb = new Node(data);
			Node *pre = this->head;
			Node *cur = pre->next;
			while (pre != NULL){
				if (head->value == id){
					isb->next = head;
					head = isb;
					break;
				}
				if (cur->value == id){
					isb->next = cur;
					pre->next = isb;
					break;
				}
				pre = pre->next;
				cur = pre->next;
			}
		}else{
			insert(data);
		}
	}
	void insert_after(int data, int id){
		if (search(id)){
			Node *q = new Node(data);
			Node *p = head;
			while (p != NULL){
				if (this->last->value == id){
					this->last->next = q;
					this->last = q;
					break;
				}
				if (p->value == id){
					q->next = p->next;
					p->next = q;
					break;
				}
				p = p->next;
			}
		}else{
			insert(data);
		}
	}
	int search(int id){
		int result = 0;
		Node *s = this->head;
		while(s != NULL){
			if (s->value == id){
				result = 1;
				break;
			}
			s = s->next;
		}
		return result;
	}
	void delete_node(int value){
		Node *p = this->head;
		Node *q;
		while (p != NULL){
			if (p->next->value == last->value && last->value == value){
				last = p;
				p->next = NULL;
				break;
			}
			if(this->head->value == value ){
				q = this->head;
				this->head = this->head->next;
				//delete q;
				break;
			}
			if(p->value == value){
				q->next = p->next;
				delete p;
				break;
			}
			q = p;
			p = p->next;
		}
	}
	void print(){
		Node *p = this->head;
		while(p != NULL){
			cout << p->value << " " << flush;
			p = p->next;
		}
		cout << endl;
	}
};



int main(){
	LinkList l;
	char menu;
	do{
		cin >> menu;
		menu = toupper(menu);
		if (menu == 'I'){
			int value,id;
			cin >> value;
			cin >> id;
			if (!l.search(value)){
				l.insert_before(value,id);
				l.print();
			}
		}
		if (menu == 'A'){
			int value,id;
			cin >> value;
			cin >> id;
			if (!l.search(value)){
				l.insert_after(value,id);
				l.print();
			}
		}
		if (menu == 'D'){
			int value;
			cin >> value;
			if(l.search(value)){
				l.delete_node(value);
			}
			l.print();
		}
	}while(menu != 'E');
	
	return 0;
}





