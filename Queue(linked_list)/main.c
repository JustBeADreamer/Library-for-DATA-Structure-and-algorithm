#include "header.h"




int main(){
    int* DATA;
    Queue_t* Q;
    int n;
    Q=(Queue_t*)malloc(sizeof(Queue_t));        //Q is public variation
    DATA=(int*)malloc(sizeof(int));
    Initialize(Q);
    
    loop:
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        Input_info(DATA);
        En_queue(*DATA, Q);
        goto loop;
    case 2:
        DATA=De_queue(DATA, Q);
        goto loop;
    case 3:
        Write_to_file(Q);
    case 4:
        Read_from_file(Q);
        goto loop;
    case 5: 
        Print(Q);
    }

}