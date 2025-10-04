#include<iostream>
using namespace std;
void SelectionSort(int arr[], int size){
	for(int i=0; i<size;i++){
		int minimumIndex = i;
		for(int j=i+1; j<size; j++){
			if(arr[minimumIndex] > arr[j]){
				minimumIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minimumIndex];
		arr[minimumIndex] = temp;
	}
}
int main(){
	int arr[5] = {2, 1, 8, 5, 3};
	SelectionSort(arr, 5);
	for(int i= 0; i<5; i++){
		cout<<arr[i]<<endl;
	}
}

