#include<iostream>
#include<string>
using namespace std;
const int SIZE = 10;

int keys[SIZE];
string values[SIZE];
bool occupied[SIZE] = {false};

int hashFunc(int key){
	return key%SIZE;
}

void insert(int key, string value){
	int index = hashFunc(key);
	int startIndex = index;
	while(occupied[index]){
		if(keys[index]==key){
			values[index] = value;
			cout<<"Value updated at key = "<<key<<" updated value = "<<value<<endl;
			return;
		}
		index = (index+1)%SIZE;
		if(index==startIndex){
			cout<<"Hash table is full. Cannot insert more values"<<endl;
			return;
		}
	}
	keys[index] = key;
	values[index] = value;
	occupied[index] = true;
	cout<<"Key = "<<key<<" inserted with value = "<<value<<endl;
}

void search(int key){
	int index = hashFunc(key);
	int startindex = index;
	while(occupied[index]){
		if(keys[index]==key){
			cout<<"Value at key = "<<key<<" is = "<<values[index]<<endl;
			return;
		}
		index = (index+1)%SIZE;
		if(startindex==index){
			break;
		}
	}
	cout<<"Key = "<<key<<" not found"<<endl;
}

void remove(int key){
	int index = hashFunc(key);
	int startIndex = index;
	
	while(occupied[index]){
		if(keys[index==key]){
			occupied[index] = false;
			cout<<"Key = "<<key<<" deleted"<<endl;
			return;
		}
		index = (index+1)%SIZE;
		if(index==startIndex){
			break;
		}
	}
	cout<<"Key = "<<key<<" not found"<<endl;
}
int main() {
    insert(1, "Alice");
    insert(11, "Bob");
    insert(21, "Charlie");

    search(11);

    remove(11);
    search(11);

    insert(11, "David");

    return 0;
}

