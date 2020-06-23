#include "header.h"



int Linear_search(int arr[], int size, int key){
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
        } 
    } 
    return -1;
}



int Sentinel_search(int arr[], int size, int key){
    int k=arr[size-1];
    arr[size-1]=key;
    int i=0;
    while(arr[i]!=key){
        i++;
    }
    arr[size-1]=k;
    if(arr[i]==key){
        return i;
    }
    else 
        return -1;
}


int Binary_search(int arr[], int l, int r, int key){
    // l <- first index
    // r -< last index 
    if(r >= l) {
        int mid = l + (r-l) / 2;
        if(arr[mid] < key) {
            return Binary_search(arr, mid + 1, r, key);
        }
        else if(arr[mid] > key){
            return Binary_search(arr, l, mid - 1, key);
        }
        else if(arr[mid]==key){
            return mid;
        }
    }
    return -1;
}
