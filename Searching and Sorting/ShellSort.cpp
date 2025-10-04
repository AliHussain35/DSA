#include<iostream>
using namespace std;
void ShellSort(int arr[], int size){
	for(int gap = size/2; gap>0; gap/=2){
		for(int i=gap; i<size; i++){
		int value = arr[i];
		int j = i-gap;
		while(j>=0 && arr[j]>value){
			arr[j+gap] = arr[j];
			j -= gap;
		}
		arr[j+gap] = value;
	   }
	}
}
int main(){
	int arr[5] = {2, 1, 8, 5, 3};
	ShellSort(arr, 5);
	for(int i= 0; i<5; i++){
		cout<<arr[i]<<endl;
	}
}
