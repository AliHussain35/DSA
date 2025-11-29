#include<iostream>
#include<string>
using namespace std;

const int SIZE = 10;
int keys[SIZE];
string values[SIZE];
bool occupied[SIZE] = {false};

int hashFunc(int key){
	return (key%SIZE);
}

void insert(int key, string value){
	int index = hashFunc(key);
	int i = 0;
	while(occupied[index]){
		if(keys[index]==key){
			values[index] = value;
			cout<<"Updated key = "<<key<<" with value = "<<value<<endl;
			return;
		}
		i++;
		index = (hashFunc(key) + i*i)%SIZE;
		if(i==SIZE){
			cout<<"Hash table full! cannot enter more values"<<endl;
			return;
		}
	}
	keys[index] = key;
	values[index] = value;
	occupied[index] = true;
	cout<<"Value inserted at key = "<<key<<endl;
}

void search(int key){
	int index = hashFunc(key);
	int i = 0;
	while(occupied[index]){
		if(keys[index]==key){
			cout<<"Value at key = "<<key<<" is = "<<values[index]<<endl;
			return;
		}
		i++;
		index = (hashFunc(key) + i*i)%SIZE;
		if(i==SIZE){
			break;
		}
	}
	cout<<"Value not found at key = "<<key<<endl;
}

void remove(int key){
	int index = hashFunc(key);
	int i=0;
	while(occupied[index]){
		if(keys[index]==key){
			occupied[index]=false;
			cout<<"Key = "<<key<<" deleted"<<endl;
			return;
		}
		i++;
		index = (hashFunc(key) + i*i)%SIZE;
		if(i==SIZE){
			break;
		}
	}
	cout<<"key = "<<key<<" not found"<<endl;
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

