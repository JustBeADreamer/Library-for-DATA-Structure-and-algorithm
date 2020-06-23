#include "header.h"



void Write_to_file(FILE *fp, int num, address *arr){
    int i;
    for(i=0;i<num;i++){
        fwrite(arr+i, sizeof(address), 1, fp);
    }
}

int Read_from_file(FILE *fp, address *arr){
    long num;
    
    fseek(fp, 0, SEEK_END);
    num=ftell(fp)/sizeof(address);
    rewind(fp);
    
    fread(arr, sizeof(address), (int)num, fp);
    return (int)num;
}

void Input_array(address *arr){
    printf("Input Name: \n");
    scanf("%s", arr->name);
    printf("Input Email: \n");
    scanf("%s", arr->email);
    printf("Input Number: \n");
    scanf("%s", arr->number);
}

void Print_array(int num, address *arr){
    for(int i=0; i<num; i++){
        printf("Name: %s\n", (arr+i)->name);
        printf("email: %s\n", (arr+i)->email);
        printf("Number: %s\n\n", (arr+i)->number);
    }
}




int partition(address arr[], int low, int high){
    int i,j;
    char pivot[25];
    address TEMP;
    strcpy(pivot, arr[high].name);
    i=low-1;
    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (strcmp(pivot, arr[j].name)>0)
        {
            i++;    // increment index of smaller element
            TEMP=arr[i];
            arr[i]=arr[j];
            arr[j]=TEMP;
        }
    }
    TEMP=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=TEMP;
    return (i + 1);
}


int Quick_sort(address arr[], int low, int high){
    if(low<high){
        int pi;
        pi=partition(arr, low, high);
        Quick_sort(arr, low, pi-1);
        Quick_sort(arr, pi+1, high);
    }
}
