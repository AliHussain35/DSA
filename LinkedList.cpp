//Linked List
#include<iostream>
using namespace std;
//creating a node using a class
class Node{
	public:
		int data;
		Node* next;
		
		Node(int value){
			data = value;
			next = 0;
		}
};
//displaying a linked list
void displayLinkedlist(Node* head){
	Node* temp = head;
	while(temp != 0){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"Null"<<endl;
}
//recursive display
void recursiveDisplay(Node *head){
	if(head == 0){
		cout<<"Null"<<endl;
		return;
	}
	cout<<head->data<<"->";
	return recursiveDisplay(head->next);
}
int main(){
	Node* head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	displayLinkedlist(head);
	recursiveDisplay(head);
}
