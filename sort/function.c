#include "header.h"


void insertion(int arr[], int low, int high) {  
    // low <- first index
    //high <- last index
    int j;
    for(int i = low + 1; i <= high; i++) {
        j = i - 1;
        int temp = arr[i];
        while(temp < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

/*
void insertion(Phonebook arr[], int low, int high) {        //using array
    int j;
    for(int i = low + 1; i <= high; i++) {
        j = i - 1;
        Phonebook temp;
        temp = arr[i];
        while(strcmp(temp.name, arr[j].name) < 0 && j >= 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
*/
int partition(int arr[], int low, int high) {   //for quick sort       
    int pivot = arr[high];
    int j = low - 1;
    for(int i = low; i < high; i++) {     
        if(arr[i] < pivot) {           
            j++;
            int temp = arr[i];      //swap arr[i] and arr[j]
            arr[i] = arr[j];
            arr[j] = temp; 
        }
    }
    arr[high] = arr[j + 1];
    arr[j + 1] = pivot;

    return j + 1;
}


void quickSort(int arr[], int low, int high) {
    //low <- first index
    //high <- last index
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int low, int mid, int high) {     // for merge Sort 
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int A[size1], B[size2];
    //
    for(int i = 0; i < size1; i++) {
        A[i] = arr[low + i];
    }
    for(int i = 0; i < size2; i++) {
        B[i] = arr[mid + 1 + i];
    }
    //
    int i = 0, j = 0, k = low;
    while(i < size1 && j < size2) {
        if(A[i] > B[j]) {
            arr[k] = B[j];
            j++;
        }
        else {
            arr[k] = A[i];
            i++;
        }
        k++;
    }
    while(i < size1) {
        arr[k] = A[i];
        i += 1;
        k += 1;
    }
    while(j < size2) {
        arr[k] = B[j];
        j += 1;
        k += 1;
    }
}

void mergeSort(int arr[], int low, int high) {  
    //low <- first index
    //high <- last index
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


void heapify(int arr[], int size, int i) {
    int large = i;
    int left = 2 * large + 1;
    int right = 2 * large + 2;

    if(left < size && arr[large] < arr[left]) {
        large = left;
    }
    if(right < size && arr[large] < arr[right]) {
        large = right;
    }
    //
    if(large != i) {
        int temp = arr[i];  //swap arr[i] and arr[large]
        arr[i] = arr[large];
        arr[large] = temp;
        //
        heapify(arr, size, large);
    }
}

void heapSort(int arr[], int size) {
    for(int i = size / 2 - 1; i >= 0; i--) {        //build max heap
        heapify(arr, size, i);
    }
    //
    for(int i = size - 1; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        //
        heapify(arr, i, 0);
    }
}


