#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct data_t{
    char name[20];
    char food[20];
    struct data_t* next;
}Data_t;


Data_t *Make_new_node_d(char name[20], char food[20]){
    Data_t* New;
    New=(Data_t*)malloc(sizeof(Data_t));
    if(New==NULL){
        printf("Error for allocating memory!!!");
        return NULL;
    }
    else
        strcpy(New->name, name);
        strcpy(New->food, food);
        New->next=NULL;
    return New;
}


Data_t* insertEnd_d(Data_t* head, Data_t* New){
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


void print_list_d(Data_t* head){
    Data_t* cur;
    if(head==NULL)
        printf("List_t empty!!!");


    else{
        cur=head;
        while(cur!=NULL){
            printf("%s %s\n", cur->name, cur->food);
            cur=cur->next;
            }
        }
}







//question 2


typedef struct food_t{
    char food[20];
    int count;
    struct food_t* next;
}Food_t;


typedef struct person_t{
    char name[20];
    Food_t* root_f;
    int Meal;
    struct person_t* left;
    struct person_t* right;
}Person_t;



Food_t* Search_f(Food_t* root, char food[20]){
    Food_t* cur;
    cur=root;
    while(cur!=NULL){
        if(strcmp(cur->food, food)==0)
            return cur;
        cur=cur->next;
    }
    return cur;
}



Food_t *Make_new_node_f(char food[20]){
    Food_t* New;
    New=(Food_t*)malloc(sizeof(Food_t));
    if(New==NULL){
        printf("Error for allocating memory!!!");
        return NULL;
    }
    else
        strcpy(New->food, food);
        New->count=1;
        New->next=NULL;
    return New;
}





Food_t* insertEnd_f(Food_t* head, Food_t* New){
    Food_t* cur=head;

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



void print_list_f(Food_t* head){
    Food_t* cur;
    if(head==NULL)
        printf("List_t empty!!!");


    else{
        cur=head;
        while(cur!=NULL){
            printf("%s:%d ", cur->food, cur->count);
            cur=cur->next;
            }
        }
}










Person_t* Search_p(Person_t* root, char name[20]){ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || strcmp(root->name, name)==0) 
       return root; 
     
    // Key is greater than root's key 
    if (strcmp(root->name, name)<0) 
       return Search_p(root->right, name); 
  
    // Key is smaller than root's key 
    return Search_p(root->left, name); 
} 



Person_t* Make_new_node_p(char name[20], char food[20]){
    Person_t* New;
    New=(Person_t*)malloc(sizeof(Person_t));
    strcpy(New->name, name);
    New->root_f=NULL;
    New->root_f=insertEnd_f(New->root_f, Make_new_node_f(food));
    New->Meal=0;
    New->left=NULL;
    New->right=NULL;
    return New;
}


Person_t* Insertion_p(Person_t* root, Person_t* New){   
    if(root==NULL){
        return New;
    }
    else if(root!=NULL){
    if (strcmp(New->name, root->name)<0) 
        root->left=Insertion_p(root->left, New); 
    else if (strcmp(New->name, root->name)>0)
        root->right=Insertion_p(root->right, New);
    }     
    return root;
}









void Inorder_tranver_p(Person_t* root){
    if(root!=NULL){
        Inorder_tranver_p(root->left); 
        printf("%s ", root->name);
        print_list_f(root->root_f); 
        printf("\n");
        Inorder_tranver_p(root->right); 
    }
}



void calculate(Person_t* root, Person_t** MAX){
    Person_t* cur_p;
    Food_t* cur_f;
    int c=0;
    cur_p=root;
    cur_f=cur_p->root_f;
    while(cur_f!=NULL){
        c=cur_f->count;
        cur_p->Meal=cur_p->Meal+c;
        cur_f=cur_f->next;
    }
    
    if(cur_p->Meal>(**MAX).Meal)
        *MAX=cur_p;
}


void calculate_ttm(Person_t* root, Person_t** MAX){
    if(root!=NULL){
        calculate_ttm(root->left, MAX);
        calculate(root, MAX);
        calculate_ttm(root->right, MAX);
    }
}



void print_list_nf(Food_t* head){
    Food_t* cur;
    if(head==NULL)
        printf("List_t empty!!!");


    else{
        cur=head;
        while(cur!=NULL){
            printf("%s:%d\n", cur->food, cur->count);
            cur=cur->next;
            }
        }
}







FILE* fp;



int main(){

int n;
    char name[20], food[20];
    Data_t* root_d=NULL;
    Data_t* cur_d=NULL;
    Person_t* root_p=NULL;
    Person_t* cur_p=NULL;
    Food_t* cur_f=NULL;
    Food_t* head_f=NULL;
    Person_t* MAX;
    MAX=(Person_t*)malloc(sizeof(Person_t));
    MAX->Meal=0;
    
    fp=fopen("input.txt", "r");
    while(fscanf(fp, "%s %s", name, food)!=EOF){
        root_d=insertEnd_d(root_d, Make_new_node_d(name, food));
        
        
        cur_f=Search_f(head_f, food);
        if(cur_f==NULL){
            head_f=insertEnd_f(head_f, Make_new_node_f(food));
        }
        else if(cur_f!=NULL){
            cur_f->count++;
        }




        
        cur_p=Search_p(root_p, name);
        if(cur_p==NULL){
            root_p=Insertion_p(root_p, Make_new_node_p(name, food));
        }

        else if(cur_p!=NULL){
            cur_f=Search_f(cur_p->root_f, food);
            if(cur_f==NULL){
                cur_p->root_f=insertEnd_f(cur_p->root_f, Make_new_node_f(food));
            }
            else if(cur_f!=NULL){
                cur_f->count++;
            }
        }
    
    }

    calculate_ttm(root_p, &MAX);


    
    fclose(fp);



    printf("Choose what you want to do: \n");
    printf("1: Print the List.\n");
    printf("2: Print people and thier food.\n");
    printf("3: Who ate the most.\n");
    printf("4: Food and thier equity.\n");
    printf("5: Exit.\n");
    scanf("%d", &n);















    switch (n){
        case 1:{
            print_list_d(root_d);
        }
        case 2:{
            Inorder_tranver_p(root_p);
        }
        case 3:{ 
            printf("%s ate the most with %d meals", MAX->name, MAX->Meal);
        }
        case 4:{
            print_list_nf(head_f);
        }    
    }
}