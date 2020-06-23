#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone_address{
    char name[25];
    char email[25];
    char number[11];
}address;


int Read_from_file(FILE *fp, address *arr);

void Write_to_file(FILE *fp, int num, address *arr);

void Input_array(address *arr);

void Print_array(int num, address *arr);

int partition(address arr[], int low, int high);

int Quick_sort(address arr[], int low, int high);