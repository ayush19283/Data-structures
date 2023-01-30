#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		Node* next;
		Node* prev;
		int data;

};
Node* head= NULL;
Node* top= NULL;  //top of the stack pointer

// checking whether stack is empty or not
bool empty(){
	if(head==NULL)
		return true;
	return false;
}

// this will be done in O(1) time
void push(int new_Data){
	Node* new_node = new Node();
	new_node->data=new_Data;
	if(top==NULL){
		new_node->prev=NULL;
		new_node->next=NULL;
		head=new_node;
		top=new_node;
	}
	else{
		top->next=new_node;
		new_node->prev=top;
		new_node->next=NULL;
		top=new_node;

	}

}

// this will also take O(1) time
void pop(){
	struct Node * deleted_node;
	deleted_node=top;
	if(empty()){
		
	}
	else if(top == head){
		head=NULL;
		top=NULL;
		free(deleted_node);
		cout<<"element poped\n";
	}
	else{
		top->prev->next=NULL;
		top=deleted_node->prev;
		free(deleted_node);
		cout<<"element poped\n";
	}
}

// this will take O(n) time as we are traversing the complete array
void display(){
	if(!empty()){
		Node* ptr=top;
		while(ptr!=NULL){
			cout<<ptr->data<<endl;
			ptr=ptr->prev;
		}
	}
}

// this will take O(1) time 
void top_element(){
	if(top==NULL){
		cout<<"stack is empty";

	}else{
		cout<<"Top element of the stack is "<<top->data<<endl;
		
	}
}

// this will take O(n) time
void size_of_stack(){
	if(top==NULL){
		cout<<"The stack is empty";
	}
	else{
	Node* ptr=head;
	int c=0;
	while(ptr!=NULL){
		c++;
		ptr=ptr->next;
	}
	cout<<"the size of the stack is "<<c<<endl;
	}
}

int main(){
	Node* head= NULL;
	Node* top= NULL;

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	pop();
	top_element();
	size_of_stack();
	display();
	return 0;
}