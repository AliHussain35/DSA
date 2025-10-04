#include<iostream>
using namespace std;
void combSort(int arr[], int size){
	int gap = size;
	bool noSwap = false;
	while(gap>1 || !noSwap){
		noSwap = true;
		gap = gap/1.3;
		if(gap<1){
			gap=1;
		}
		for(int i=0; i+gap<size; i++){
			if(arr[i]>arr[i+gap]){
				int temp = arr[i];
				arr[i] = arr[i+gap];
				arr[i+gap] = temp;
				noSwap = false;
			}
		}
	}
}
int main(){
	int arr[5] = {2, 1, 8, 5, 3};
	combSort(arr, 5);
	for(int i= 0; i<5; i++){
		cout<<arr[i]<<endl;
	}
}
