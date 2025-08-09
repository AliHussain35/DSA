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
//Inserting at last of the linked list
void InsertLast(Node* head, int x){
	Node* t = new Node(x);
	t->next = 0;
	//check if there are already nodes in a linked list or it is empty
	if(head==0){
		head = t;
	}
	else{
		Node* temp = head;
		while(temp->next != 0){
			temp = temp->next;
		}
		temp->next = t;
	}
}
//Inserting in a sorted linked list
void InsertinSorted(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // Case 1: Insert at beginning or list is empty
    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Traverse and insert in the correct sorted position
    Node* q = nullptr;
    Node* temp = head;

    while (temp != nullptr && value > temp->data) {
        q = temp;
        temp = temp->next;
    }
    q->next = newNode;
    newNode->next = temp;
}
//Deleting a node from a linked list
// 1. deleting first node
// 2. deleting node at a given position
void deleteFirstNode(Node* head){
	//take a pointer p on the first node to deallocate the memory
	Node* p = head;
	head = head->next;
	delete p;
}
void deleteAtPosition(Node* head, int position){
	Node* q = 0;
	Node* temp = head;
	for(int i=0; i<position-1; i++){
		q = temp;
		temp = temp->next;
	}
	q->next = temp->next;
	delete temp;
}
//Finding if a given linked list is sorted or not 
void checkSorted(Node* head){
    if(head == 0 || head->next == 0){
        cout<<"Linked list is sorted"<<endl;
        return;
    }
    int flag = 0;
    int x = head->data;      
    Node* temp = head->next;  
    while(temp != 0){
        if(x > temp->data){
            flag = 1;
            break;
        }
        x = temp->data;
        temp = temp->next;
    }
    if(flag == 1){
        cout<<"Linked list is not sorted"<<endl;
    }else{
        cout<<"Linked list is sorted"<<endl;
    }
}
//Removing duplicate elements from a linked list
void removeDuplicates(Node* head){
	Node* q = head;
	Node* p = head->next;
	while(p !=0){
		if(q->data == p->data){
			q->next = p->next;
			delete p;
			p = q->next;
		}
		p = q;
		q = q->next;
	}
}
//reversing a linked list
// 1. reversing elements (using array to first copy elements and then reverse copy them)
// 2. reversing links
void reversingElements(Node* head, int length){
	Node* p =head;
	int array[length];
	int index = 0;
	//first copy all the elements
	while(p != 0){
		array[index] = p->data;
		p = p->next;
		index++;
	}
	//now copy them back in a reverse order
	p = head;
	index--;
	while(p!=0){
		p->data = array[index--];
		p = p->next;
	}
} //this method needs extra space as we are creating an additional array
//method 2 = using sliding pointers (3 pointers)
void reversingLinks(Node* head){
	Node* p = head;
	Node* q = 0;
	Node* r = 0;
	while(p !=0){
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}//we prefer modifying links rather than working with elements in the linked list
//concatenation of 2 linked lists
void concatenate(Node* head, Node *secHead){
	Node* p;
	while(p->next != 0){
		p = p->next;
	}//now we have reached to the last node of the first linked list
	
	p->next = secHead;
	secHead = 0;
}
//merging 2 sorted linked lists into 1 sorted linked list
void merge(Node* first, Node* second){
	Node* third;
	Node* last;
	if(first->data<second->data){
		third = first;
		last = first;
		first = first->next;
		last->next = 0;
	}
	else{
		third = second;
		last = second;
		second = second->next;
		last->next = 0;
	}
	
	while(first != 0 && second!=0){
		if(first->data<second->data){
			last->next = second;
			second = second->next;
			last = second;
			last->next = 0;
		}
		else{
			last->next = first;
			first = first->next;
			last = first;
			last->next = 0;
		}
	}
	if(first==0){
		last->next = second;
	}
	else{
		last->next = first;
	}
}
void isLoop(Node* head){
    Node* p = head;// slow
    Node* q = head;// fast

    while(p && q && q->next) {
        p = p->next;          // move slow 1 step
        q = q->next->next;    // move fast 2 steps

        if(p == q){ 
            cout<< "The linked list is loop"<<endl;
            return;
        }
    }

    cout << "The linked list is linear" << endl;
}
//Circular Linked List
void display(Node* head) {
    if(head == nullptr)  // empty list
        return;

    Node* p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p != head); // stop when we loop back to head
}
//Inserting in a circular linked list
// 1. Inserting before head node
// 2. Inserting at any given position (same as the normal procedure)
void InsertatPosition(Node* head, int pos, int data){
	Node* t = new Node(data);
	Node* p = head;
	for(int i=0; i<pos-1; i++){
		p = p->next;
	}
	t->next=p->next;
	p->next = t;
}
void InsertBeforeHead(Node*& head, int data) { // pass by reference so head updates
    Node* t = new Node(data);
    if (head == nullptr) { // empty list
        t->next = t; // point to itself
        head = t;
        return;
    }
    Node* p = head;
    while (p->next != head) { // find last node
        p = p->next;
    }
    t->next = head; // new node points to old head
    p->next = t;    // last node points to new node
    head = t;       // update head to new node
}
//Delete Operations in a circular linked list
// 1. Delete Head Node
// 2. Delete a Node from a given position
void DeleteHeadNode(Node*& head) {
    if (head == nullptr) // empty list
        return;
    if (head->next == head){ // only one node
        delete head;
        head = nullptr;
        return;
    }
    Node* p = head;
    while (p->next != head) { // find last node
        p = p->next;
    }
    Node* temp = head;        // old head to delete
    p->next = head->next;     // last node points to 2nd node
    head = head->next;        // update head
    delete temp;              // free memory
}
void DeleteFromPosition(Node* head, int pos){
	Node* p = head;
	for(int i=0; i<pos-2; i++){
		q=p;
		p=p->next;
	}
	Node* q;
	q = p->next;
	p->next = q->next;
	delete q;
}

int main(){
	Node* head = new Node(10);
	head->next = new Node(40);
	head->next->next = new Node(30);
	head->next->next->next = new Node(20);
	displayLinkedlist(head);
	recursiveDisplay(head);
	int totalNodes = recursiveCount(head);
	cout<<totalNodes<<endl;
	int sum = recursiveSum(head);
	cout<<sum<<endl;
	printmaxElement(head);
}
