#include<iostream>
using namespace std;

int getMax(int arr[], int n){
    int mx = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > mx) mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[100];        // FIXED SIZE ARRAY
    int count[10] = {0};

    // Count digits
    for(int i=0; i<n; i++){
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Cumulative count
    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    // Build output (stable)
    for(int i=n-1; i>=0; i--){
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back
    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int mx = getMax(arr, n);
    for(int exp = 1; mx/exp > 0; exp *= 10){
        countSort(arr, n, exp);
    }
}

int main(){
    int arr[5] = {11, 23, 88, 1, 32};
    radixSort(arr, 5);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
}

