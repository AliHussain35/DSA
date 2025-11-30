#include<iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end){
	int i = start;
	int j = mid+1;
	int temp[end-start+1];
	int k = 0; //pointer for temp array
	
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	
	//copy remaining
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=end){
		temp[k++] = arr[j++];
	}
	
	//copy back
	for(int x=0; x<k; x++){
		arr[start+x] = temp[x];
	}
	
}

void mergeSort(int arr[], int start, int end){
	if(start<end){
		int mid= (start+end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main(){
	int arr[5] = {11, 23, 88, 1, 32};
	mergeSort(arr, 0, 4);
	for(int i=0; i<5; i++){
		cout<<arr[i]<<" ";
	}
}
