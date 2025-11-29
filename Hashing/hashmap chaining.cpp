#include<iostream>
#include<string>
using namespace std;

const int SIZE = 10;
class Node{
	public:
		int key;
		string value;
		Node* next;
};

Node* table[SIZE] = {0};

int hashFunc(int key){
	return key%SIZE;
}

void insert(int key, string value){
	int index = hashFunc(key);
	Node* head = table[index];
	
	Node* temp = head;
	while(temp!=0){
		if(temp->key==key){
			temp->value = value;
			cout<<"Value updated "<<" at key = "<<key<<endl;;
			return;
		}
		temp= temp->next;
	}
	Node* newNode = new Node{key, value, head};
	table[index] = newNode;
	cout<<"Key inserted successfully"<<endl;
}
void remove(int key){
	int index = hashFunc(key);
	Node* temp = table[index];
	Node* prev = 0;
	while(temp!=0){
		if(temp->key==key){
			if(prev==0){
				table[index] = temp->next;
			}
			else{
				prev->next = temp->next;
			}
			delete temp;
			cout<<"Key deleted = "<<key<<endl;
			return;
		}
		prev = temp;
		temp = temp->next;
	}
	cout<<"key = "<<key<<" not found "<<endl;
}
void searchkey(int key){
	int index = hashFunc(key);
	Node* temp = table[index];
	while(temp!=0){
		if(temp->key==key){
			cout<<"key = "<<key<<" found with value = "<<temp->value<<endl;
			delete temp;
			return;
		}
		temp=temp->next;
	}
	cout<<"Key = "<<key<<" not found"<<endl;
}
void display(){
	cout<<"HASH TABLE Chaining"<<endl;
	for(int i=0; i<SIZE; i++){
		cout << "[" << i << "]: ";
        Node* temp = table[i];

        if (!temp) {
            cout << "Empty\n";
            continue;
        }

        while (temp != 0) {
            cout << "(" << temp->key << ", " << temp->value << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    cout << endl;
}

int main(){
	insert(1, "Alice");
    insert(11, "Bob");
    insert(21, "Charlie");
    display();

    searchkey(11);
    remove(11);
    searchkey(11);
    display();

    insert(11, "David");
    display();

    return 0;
}


