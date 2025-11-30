#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i= low-1;
	for(int j=low; j<high; j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quicksort(int arr[], int low, int high){
	if(low<high){
		int pivot = partition(arr, low,high);
		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
	}
}

int main(){
	int arr[5] = {11, 23, 88, 1, 32};
	quicksort(arr, 0, 4);
	for(int i=0; i<5; i++){
		cout<<arr[i]<<" ";
	}
}
