#include<iostream>
using namespace std;
int BinarySearch(int arr[], int size, int value){
	int high = size-1;
	int low = 0;
	while(low<=high){
		int mid = (high + low)/2;
		if(arr[mid]==value){
			return mid;
		}
		else if(arr[mid]>value){
			high = mid -1;
		}
		else{
			low = mid+1;
		}
	}
	return -1;
}
int main(){
	int arr[5] = {2, 3, 7, 9, 10};
	int index= BinarySearch(arr, 5, 7);
	cout<<index;
}
