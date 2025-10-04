#include<iostream>
using namespace std;
int InterpolationSearch(int arr[], int size, int value){
	int high = size-1;
	int low = 0;
	int position;
	while(low<=high){
		if(arr[high]==arr[low]){
			if(arr[low]==value){
				return low;
			}
			return -1;
		}
		
		position = low + ((double)(value-arr[low])*(high-low)/(arr[high]-arr[low]));
		if(position<low || position >high){
			break;
		}
		if(arr[position]==value){
			return position;
		}
		else if(arr[position]>value){
			high = position -1;
		}
		else{
			low = position +1;
		}
	}
	return -1;
}
int main(){
	int arr[5] = {2, 3, 7, 9, 10};
	int index= InterpolationSearch(arr, 5, 7);
	cout<<index;
}
