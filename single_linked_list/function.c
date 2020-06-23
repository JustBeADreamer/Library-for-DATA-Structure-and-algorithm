#include "header.h"



//THIS IS FOR THE FILE NAME
char filename[]="phonebook";
FILE *fp;



int IsEmpty(List_t* head){
    return head==NULL;
}



void Input_info(int* DATA){
    printf("input DATA:  \n");
    scanf("%d", DATA);
}


List_t *Make_new_node(int DATA){
    List_t* New;
    New=(List_t*)malloc(sizeof(List_t));
    if(New==NULL){
        printf("Error for allocating memory!!!");
        return NULL;
    }
    else
        New->DATA=DATA;
        New->next=NULL;
    return New;
}




List_t* insertFirst(List_t* head, List_t* New){
    New->next=head;
    head=New;
    return head;
}





List_t* insertEnd(List_t* head, List_t* New){
    List_t* cur=head;

    if(IsEmpty(head)){
        New->next=head;
        head=New;
        return head;
    }
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=New;
    return head;
 
}




List_t* Delete_Node(List_t* head){
    int n;
    int i=1;
    List_t* cur=head;

    List_t *prev;

    if(IsEmpty(head)){
        printf("The List_t has nothing to delete.\n");
        return head;
    }
    else{
        printf("input the position of the node that you want to delete: \n");
        scanf("%d", &n);
        while(i!=n){
            if(cur->next==NULL&&(i!=n)){
                printf("No such position exists\n");
                getch();
                return head;
            }
            else{
                prev=cur;
                cur=cur->next;
                i++;
            }
        }    
    }
    if(i==1){
        head=cur->next;
        free(cur);
        return head;
    }
    else{
        prev->next=cur->next;
        free(cur);
        return head;
    }
}


List_t* DeleteFirst(List_t* head){
    List_t* cur=head;
    head=cur->next;
    free(cur);
    return head;
}



List_t* DeleteEnd(List_t* head){
    List_t* prev;
    List_t* cur=head;
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    free(cur);
    return head;
}

List_t* Free_list(List_t* head){
    List_t* cur=head;
    while(cur!=NULL){
        head=head->next;
        free(cur);
        cur=head;
    }
    return head;
}


List_t* Reverse_list(List_t* head){
    List_t* prev;
    List_t* cur;
    prev=cur=NULL;
    while(!IsEmpty(head)){
        cur=head;
        head=head->next;
        cur->next=prev;
        prev=cur;
    }
    head=prev;
    return head;
}


void print_list(List_t* head){
    List_t* cur;
    system("cls");
    if(IsEmpty(head))
        printf("List_t empty!!!");


    else{
        cur=head;
        printf("DATA\n");
        while(cur!=NULL){
            printf("%d\n", cur->DATA);
            cur=cur->next;
            }
        }
}

List_t* Write_to_file(List_t* head){
    List_t* cur;
    if((fp=fopen(filename, "wb"))==NULL){
        printf("Cannot open file %s", filename);
        return head;
    }
    else{
        cur=head;
        while(cur!=NULL){
            fwrite(cur, sizeof(List_t), 1, fp);
            cur=cur->next;
        }
        fclose(fp);
        return head;
    }
}


List_t* Read_from_file(List_t* head){
    int num;
    int i=1;
    List_t* cur=NULL;
    head=NULL;
    List_t *prev;

    if((fp=fopen(filename, "rb"))==NULL){
        printf("Cannot open file %s", filename);
        return head;
    }

    else{
        fseek(fp, 0, SEEK_END);
        num=ftell(fp)/sizeof(List_t);
        rewind(fp);

        while(i<=num){
            if(i==1){
                head=(List_t*)malloc(sizeof(List_t));
                fread(head, sizeof(List_t), 1, fp);
                prev=head;
                i++;
            }
            else if(i>1){
                cur=(List_t*)malloc(sizeof(List_t));
                fread(cur, sizeof(List_t), 1, fp);
                prev->next=cur;
                prev=prev->next;
                i++;
            }
        }
    }
    fclose(fp);
    return head;
}