#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>




// THIS IS FOR DATA_t


typedef struct name_food{
    char name[20];
    char food[20];
}Namefood_t;


typedef struct data_t
{
    Namefood_t DATA;
    struct data_t* next;
}Data_t;


int IsEmpty(Data_t* head_d){
    return head_d==NULL;
}


Data_t *Make_new_node(Namefood_t DATA){
    Data_t* New=(Data_t*)malloc(sizeof(Data_t));
    if(New==NULL){
        printf("Error for allocating memory!!!");
        return NULL;
    }
    else
        New->DATA=DATA;
        New->next=NULL;
    return New;
}





Data_t* insertEnd(Data_t* head, Data_t* New){
    Data_t* cur=head;
    if(head==NULL){
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


void print_list(Data_t* head){
    Data_t* cur;
    if(IsEmpty(head))
        printf("List_t empty!!!");
    else{
        cur=head;
        while(cur!=NULL){
            printf("%s %s\n", cur->DATA.name, cur->DATA.food);
            cur=cur->next;
            }
        }
}










//This is for turning Inputed data to tree


typedef struct food_t{
    char food[20];
    int count;
    struct food_t* next;
}Food_t;


typedef struct person_t{
    char name[20];
    Food_t* root_f;
    int ttmeal;
    struct person_t *next;
}Person_t;



int IsEmpty_f(Food_t* head_d){
    return head_d==NULL;
}


Food_t* Search_f(Food_t* root, Namefood_t DATA){
    Food_t* cur=NULL;
    cur=root;
    while (cur!=NULL)
    {
        if(strcmp(cur->food, DATA.food)==0)
            return cur;
        cur=cur->next;
    }
    return cur;
    
}

Food_t *Make_new_node_f(Namefood_t DATA){
    Food_t* New=(Food_t*)malloc(sizeof(Food_t));
    if(New==NULL){
        printf("Error for allocating memory!!!");
        return NULL;
    }
    else
        strcpy(New->food, DATA.food);
        New->count=1;
        New->next=NULL;
    return New;
}





Food_t* insertEnd_f(Food_t* root, Food_t* New){
    Food_t* cur=root;
    if(root==NULL){
        New->next=root;
        root=New;
        return root;
    }
    while(cur->next!=NULL){ 
        cur=cur->next;
    }
    cur->next=New;
    return root;
}

void print_list_f(Food_t* head){
    Food_t* cur;
    if(IsEmpty_f(head))
        printf("Food_t empty!!!");
    else{
        cur=head;
        while(cur!=NULL){
            printf("%s:%d ", cur->food, cur->count);
            cur=cur->next;
            }
        }
}











int IsEmpty_p(Person_t* head_d){
    return head_d==NULL;
}


Person_t* Search_p(Person_t* root, Namefood_t DATA){
    Person_t* cur=NULL;
    cur=root;
    while (cur!=NULL)
    {
        if(strcmp(cur->name, DATA.name)==0)
            return cur;
        cur=cur->next;
    }
    return cur;
}

Person_t *Make_new_node_p(Namefood_t DATA){
    Person_t* New=(Person_t*)malloc(sizeof(Person_t));
    if(New==NULL){
        printf("Error for allocating memory!!!");
        return NULL;
    }
    else
        strcpy(New->name, DATA.name);
        New->root_f=NULL;
        New->ttmeal=0;
        New->root_f=(New->root_f, Make_new_node_f(DATA));
        New->next=NULL;
    return New;
}





Person_t* insertEnd_p(Person_t* root, Person_t* New){
    Person_t* cur=root;
    if(root==NULL){
        New->next=root;
        root=New;
        return root;
    }
    while(cur->next!=NULL){ 
        cur=cur->next;
    }
    cur->next=New;
    return root;
}

void print_list_p(Person_t* head){
    Person_t* cur;
    if(IsEmpty_p(head))
        printf("List_t empty!!!");
    else{
        cur=head;
        while(cur!=NULL){
            printf("%s ", cur->name);
            print_list_f(cur->root_f);
            printf("\n");
            cur=cur->next;
            }
        }
}




void Ttmeal(Person_t* head){
    Person_t* cur_p=NULL;
    Food_t* cur_f=NULL;
    int COUNT=0;
    int c=0;
    cur_p=head;
    while(cur_p!=NULL){
        COUNT=0;
        cur_f=cur_p->root_f;
        while(cur_f!=NULL){
            c=cur_f->count;
            COUNT=COUNT+c;
            cur_f=cur_f->next;
        }
        cur_p->ttmeal=COUNT;
        cur_p=cur_p->next;
    }
}


void print_list_tt(Food_t* head){
    Food_t* cur;
    if(IsEmpty_f(head))
        printf("Food_t empty!!!");
    else{
        cur=head;
        while(cur!=NULL){
            printf("\n");
            printf("%s:%d \n", cur->food, cur->count);
            cur=cur->next;
            }
        }
}







char filename[]="input.txt";
FILE *fp;


int main(){
    Data_t* head_d=NULL;
    Data_t* cur_d=NULL;
    Person_t* root_p=NULL;
    Person_t* cur_p=NULL;
    Food_t* cur_f;
    Food_t* ttcount=NULL;
    Food_t* cur_tt=NULL;
    Namefood_t DATA;
    Person_t TTmax;
    int c=0;
    int numofper=0;
    TTmax.ttmeal=0;
    
    fp=fopen("input.txt", "r");
    while(fscanf(fp, "%s %s", &DATA.name, &DATA.food)!=EOF){
        head_d=insertEnd(head_d, Make_new_node(DATA));



        cur_tt=Search_f(ttcount, DATA);
        if(cur_tt==NULL){
            ttcount=insertEnd_f(ttcount, Make_new_node_f(DATA));
        }
        else if(cur_tt!=NULL){
            cur_tt->count++;
        }



        cur_p=Search_p(root_p, DATA);
        if(cur_p==NULL){
            root_p=insertEnd_p(root_p, Make_new_node_p(DATA));
        }
        else if(cur_p!=NULL){
            cur_f=Search_f(cur_p->root_f, DATA);
            if(cur_f==NULL){
                insertEnd_f(cur_p->root_f, Make_new_node_f(DATA));

            }
            else if(cur_f!=NULL){
                cur_f->count++;
            }
        }
    }    
    fclose(fp);
    Ttmeal(root_p);
    cur_p=root_p;
    
    
    
    while (cur_p!=NULL)
    {
        if(cur_p->ttmeal>TTmax.ttmeal)                                                  //find who ate the most
            TTmax=*cur_p;
        cur_p=cur_p->next;
    }

    cur_p=root_p;
    while(cur_p!=NULL){
        cur_p=cur_p->next;
        numofper++;
    }

    printf("number: %d", (int)numofper);

    print_list(head_d);
    printf("\n");
    print_list_p(root_p);
    printf("\n");
    printf("%s eat the most with %d meal", TTmax.name, TTmax.ttmeal);
    printf("\n");
    print_list_tt(ttcount);
    return 0;

}
