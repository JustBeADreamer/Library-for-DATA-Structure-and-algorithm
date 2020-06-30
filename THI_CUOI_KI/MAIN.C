#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>


int main ()
{
    int choice;
    do {
        do {
            printf("\n\n\tMENU\n");
            printf("1. Print out information\n");
            printf("2. Print information of each plane\n");
            printf("3. Search flight number\n");
            printf("4. Counting time for taking luggages\n");
            printf("0. Quit\n");
            
            printf("Your choice: ");
            scanf("%d", &choice);

            if(choice == 1) {

            }
            else if(choice == 2) {
                
            }
            else if(choice == 3) {

            }
            else if(choice == 4) {

            }
        } while(choice != 0);
    } while(choice < 0 && choice > 4);  

    return 0;  
}

