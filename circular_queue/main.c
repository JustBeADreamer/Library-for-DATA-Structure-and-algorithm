#include "header.h"


int main(){
    int data, n;
    Make_Null(&Q);
    loop:
    system("cls");
    printf("choose: \n");
    scanf("%d", &n);
    switch (n){
        case 1:
            system("cls");
            printf("input data: \n");
            scanf("%d", &data);
            En_Queue(data, &Q);
            goto loop;
        case 2:
            system("cls");
            De_Queue(&data, &Q);
            printf("the out data: %d\n", data);
            goto loop;
        case 3:
            system("cls");
            Print_Queue(Q);
            goto loop;
    }
    return 0;
}