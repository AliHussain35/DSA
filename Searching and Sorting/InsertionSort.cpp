#include<iostream>
using namespace std;
void InsertionSort(int arr[], int size){
	for(int i=1; i<size; i++){
		int value = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>value){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = value;
	}
}
int main(){
	int arr[5] = {2, 1, 8, 5, 3};
	InsertionSort(arr, 5);
	for(int i= 0; i<5; i++){
		cout<<arr[i]<<endl;
	}
}
