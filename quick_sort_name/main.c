#include "header.h"

address arr[100];
FILE *fp;
char filename[]="address_book";

int main (){
    int num=0;
    int i;

    for(i=0;i<3;i++){
    Input_array(&arr[i]);
    num++;
    }
    fp=fopen(filename, "wb");
    Write_to_file(fp, num, arr);
    fclose(fp);

    fp=fopen(filename, "rb");
    num=Read_from_file(fp, arr);
    printf("%d", num);
    Quick_sort(arr, 0, num-1);
    Print_array(num, arr);
    return 0;
}









