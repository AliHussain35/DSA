//Linked List
#include<iostream>
#include <climits>
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
//recursive function to find max element in a linkedlist
int findMax(Node *head){
	int x=0;
	if(head ==0){
		return MIN_INT;
	}
	x=findMax(head->next);
	if(x>head->data){
		return x;
	}
	else{
		return head->data;
	}
}
//Linear search in a linked list
Node* linearSearch(Node* head, int value){
	Node* temp = head;
	while(temp != 0){
		if(value==temp->data){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
//Recursive Linear Search
Node* recursiveLinearSearch(Node* head, int value){
	if(head==0){
		return NULL;
	}
	if(value == head->data){
		return head;
	}
	return recursiveLinearSearch(head->next, value);
}
//improve linear search by moving it on head
Node* search(Node* head, int value){
	Node* q = 0;
	Node* p = head;
	while(p != 0){
		if(p->data == value){
			q->next = p->next;
			p->next = head;
			head = p;
		}
		q = p;
		p = p->next;
	}
}
//Adding new node to a existing linked list
// 1. inserting before first (takes constant time)
// 2. inserting after a given position (takes O(n) time)
void InsertatFirst(Node* head, int nodeData){
	Node* t = new Node(nodeData);
	t->next = head;
	head = t;
}
void InsertatPosition(Node* head, int nodeData, int position){
	Node* t = new Node(nodeData);
	Node* p = head;
	for(int i=0; i<position-1; i++){
		p = p->next;
	}
	t->next = p->next;
	p->next = t;
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
