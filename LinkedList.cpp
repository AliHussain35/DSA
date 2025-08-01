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
//counting nodes in a linked list
int countNodes(Node* head){
	Node* temp = head;
	int count=0;
	while(temp != 0){
		count++;
		temp = temp->next;
	}
	return count;
}
//recursive counting
int recursiveCount(Node* head){
	if(head==0){
		return 0;
	}
	return 1+recursiveCount(head->next);
}
//sum of all elements in a linked list
int addElements(Node * head){
	int sum = 0;
	Node* temp = head;
	while(temp != 0){
		sum = sum + temp->data;
		temp= temp->next;
	}
	return sum;
}
//recursive sum of all the elements 
int recursiveSum(Node* head){
	if(head==0){
		return 0;
	}
	return head->data + recursiveSum(head->next);
}
//finding maximum element in a linkedList
void printmaxElement(Node *head){
	Node* temp = head;
	int max;
	max = temp->data;
	while(temp!= 0){
		if(temp->data > max){
			max = temp->data;
		}
		temp = temp->next;
	}
	cout<<"Maximum element = "<<max<<endl;
}
//recursive function to find max
int recursiveMaxelement(Node* head){
	if(head == 0){
		return 
	}
}
int main(){
	Node* head = new Node(10);
	head->next = new Node(40);
	head->next->next = new Node(30);
	displayLinkedlist(head);
	recursiveDisplay(head);
	int totalNodes = recursiveCount(head);
	cout<<totalNodes<<endl;
	int sum = recursiveSum(head);
	cout<<sum<<endl;
	printmaxElement(head);
}
