//Stack 
#include<iostream>
#include <climits>
using namespace std;
// 1.implement using Array
// 2.implement using LinkedList
class Stack{
	public:
		int *arr; //pointer to array
		int topIndex; //index of the top element
		int capacity; //max capacity of a stack
};
void initializeStack(Stack& s, int size){
	s.arr = new int[size];
	s.capacity = size;
	s.topIndex = -1;
}
void Push(Stack& s, int value){
	if(s.topIndex == s.capacity-1){
		cout<<"Stack is Full"<<endl;
		return;
	}
	s.topIndex++;
	s.arr[s.topIndex] = value;
	cout<<"Value Pushed Successfully"<<endl;
}
int Pop(Stack& s){
	if(s.topIndex == -1){
		cout<<"Stack is Empty"<<endl;
		return -1;
	}
	int value;
	value = s.arr[s.topIndex];
	s.topIndex--;
	return value;
}
int main(){
	Stack s;
	int n;
	cout<<"Enter the size of the Stack = ";
	cin>>n;
	initializeStack(s, n);
	Push(s, 45);
	Push(s, 10);
	int value = Pop(s);
	cout<<value;
}

