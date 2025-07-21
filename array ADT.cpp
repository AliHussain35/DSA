#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void display(struct Array a){
    for(int i = 0; i < a.length; i++){
        cout<<a.A[i] << endl;
    }
}
void Append(struct Array *arr, int x){
    if (arr->length < arr->size) {
        arr->A[arr->length] = x;
        arr->length++;
    }
}
void Insert(int index, int value, struct Array *arr){
    if (index < 0 || index > arr->length){
        cout<<"Invalid index!"<<endl;
        return;
    }

    if(arr->length >= arr->size){
        cout<<"Array is full, cannot insert!"<<endl;
        return;
    }

    for(int i = arr->length; i > index; i--){
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = value;
    arr->length++;
}
void Delete(struct Array *arr, int index){
	for(int i=index; i <arr->length-1; i++){
		arr->A[i] = arr->A[i+1];
	}
	arr->length--;
}
void Swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int LinearSearch(struct Array *arr, int value){
    for(int i = 0; i < arr->length; i++){
        if(value == arr->A[i]){
            if (i > 0) { // transposition only if i > 0
                Swap(&arr->A[i], &arr->A[i - 1]);
                return i - 1; // because element moved one step left
            }
            return i; // if it's at 0th index, return as is
        }
    }
    return -1; // not found
}
int BinarySearch(struct Array *arr, int length, int value){
	int low=0;
	int high=length-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr->A[mid] == value){
			return mid;
		}
		else if(value>arr->A[mid]){
			low = mid+1;
		}
		else{
			high = mid -1;
		}
	}
	return -1;
}
int Get(int index, struct Array *arr){
	if(index>=0 && index<arr->length){
		int value;
		value = arr->A[index];
		return value;
	}
	return -1;
}
void Set(int index, int value, struct Array *arr){
	if(index>=0 && index<arr->length){
		arr->A[index] = value;
		cout<<"Value Set"<<endl;
		return;
	}
	cout<<"Invalid index"<<endl;
}
int Max(struct Array *arr){
	int max;
	max = arr->A[i];
	for(int i=1; i<arr->length; i++){
		if(arr->A[i] > max){
			max= arr->A[i];
		}
	}
	return max;
}
int Min(struct Array *arr){
	int min;
	min = arr->A[i];
	for(int i=1; i<arr->length; i++){
		if(arr->A[i] < min){
			min= arr->A[i];
		}
	}
	return min;
}
int Sum(struct Array *arr){
	int Total = 0;
	for(int i=0; i<arr->length; i++){
		Total+= arr->A[i];
	}
	return Total;
}
int RecursiveSum(struct Array *arr, int n){
	if(n<0){
		return 0;
	}
	else{
		return RecursiveSum(*arr, n-1) + arr->A[n-1];
	}
}
void reverse(struct Array *arr){
	struct Array arr2;
	for(int i=arr->length-1, int j=0; i>=0; i--, j++){
		arr2.A[j] = arr->A[i];
	}
	for(int i=0; i<arr->length; i++){
		arr->A[i] = arr2.A[i];
	}
}
void leftShift(struct Array *arr){
	for(int i=1; i<arr->length; i++){
		arr->A[i-1] = arr->A[i];
	}
	arr->A[arr->length-1] = 0;
}
void rightShift(struct Array *arr) {
    for (int i = arr->length - 1; i > 0; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}
void leftRotate(struct Array *arr){
	int value = arr->A[0];
	for(int i=1; i<arr->length; i++){
		arr->A[i-1] = arr->A[i];
	}
	arr->A[arr->length-1] = value;
}
void rightRotate(struct Array *arr){
	int value = arr->A[arr->length-1];
	for (int i = arr->length - 1; i > 0; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = value;
}
void insertSorted(struct Array *arr, int value){
	int index = arr->length-1;
	while(arr->A[index] > value){
		arr->A[index+1] = arr->A[index];
		index--;
	}
	arr->A[index+1] = value;
}
bool sortedOrNot(struct Array *arr){
	for(int i=0; i<arr->length-1; i++){
		if(arr->A[i] > arr->A[i+1]){
			return false
		}
	}
	return true;
}
int main(){
    struct Array arr = {{2, 3, 5, 6}, 10, 4};
    Append(&arr, 10);          
    Insert(2, 43, &arr);        
    cout<<"Displaying"<<endl;
    display(arr);
    Delete(&arr, 3);
    cout<<"Updated"<<endl;
    display(arr);
    int index = LinearSearch(&arr, 3);
    cout<<"Found at = "<<index;
    display(arr);
    return 0;
}


