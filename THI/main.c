#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

typedef struct list_t{
    char ID[6];
    char name[30];
    long total;
    long electronic;
    long fashion;
    int num_electronic;
    int num_fashion;
    struct list_t* left;
    struct list_t* right;
}Node;


Node* Make_new_node(char ID[6], char name[30], long electronic, long fashion){
    Node* New;
    New=(Node*)malloc(sizeof(Node));
    strcpy(New->name, name);
    strcpy(New->ID, ID);
    New->electronic=electronic;
    New->fashion=fashion;
    New->num_electronic=0;
    New->num_fashion=0;
    New->electronic=0;
    New->fashion=0;
    New->total=0;
    if(electronic>0){
        New->num_electronic=1;
        New->total+=electronic;
        New->electronic+=electronic;
    }
    if(fashion>0){
        New->num_fashion=1;
        New->total+=fashion;
        New->fashion+=fashion;
    }
    New->left=NULL;
    New->right=NULL;
    return New;
}




Node* Insertion(Node* root, Node* New){   
    if(root==NULL){
        return New;
    }
    else if(root!=NULL){
    if (strcmp(New->ID, root->ID)<0) 
        root->left=Insertion(root->left, New); 
    else if (strcmp(New->ID, root->ID)>0)
        root->right=Insertion(root->right, New);
    }     
    return root;
}







Node* Search(Node* root, char ID[6]){ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || strcmp(root->ID, ID)==0) 
       return root; 
     
    // Key is greater than root's key 
    if (strcmp(root->ID, ID)<0) 
       return Search(root->right, ID); 
  
    // Key is smaller than root's key 
    return Search(root->left, ID); 
} 


Node* Input(Node* New,  long electronic, long fashion){
    if(electronic>0){
        New->num_electronic+=1;
        New->total+=electronic;
        New->electronic+=electronic;
    }
    if(fashion>0){
        New->num_fashion+=1;
        New->total+=fashion;
        New->fashion+=fashion;
    }
    return New;
}

void Inorder_tranver(Node* root){
    if(root!=NULL){
        Inorder_tranver(root->left); 
        printf("%s\t%s\t%d\t%ld\t%ld\n", root->ID, root->name, root->total, root->num_electronic, root->num_fashion);
        Inorder_tranver(root->right); 
    }
}


Node* postorder(Node* root, Node* Min) {  
    if(root != NULL) {
        root->left=postorder(root->left, Min);
        root->right=postorder(root->right, Min);
        if(root->total>Min->total){
            Min=root;
        }   
    }
    return Min;
}

int main ()
{
    FILE* fp;
    char ID[6];
    char name[30];
    long electronic;
    long fashion;
    Node* head=NULL;
    Node* cur=NULL;
    Node* Min;
    Min=(Node*)malloc(sizeof(Node));
    Min->total=0;



    int choice;
    do {
        do {
            printf("Welcome to ICTBestBuy");
            printf("\nMENU:\n");
            printf("1: Load Transaction Data.\n");
            printf("2: Show Statistics Data\n");
            printf("3: Manually Add Transaction\n");
            printf("4: Data Analysis\n");
            printf("0: Quit\n");
            
            printf("Your choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                fp=fopen("giaodich.txt", "r");
                while(fscanf(fp, "%s %s %ld %ld", ID, name, &electronic, &fashion)!=EOF){
                    cur=Search(head, ID);

                    if(cur==NULL){
                        head=Insertion(head, Make_new_node(ID, name, electronic, fashion));
                    }
                    else if(cur!=NULL){
                        cur=Input(cur, electronic, fashion);
                       
                    }
                    cur=Search(head, ID);
                    printf("%s\t%s\t%ld\t%ld\t%p\n", ID, name, electronic, fashion, cur);
                }
                fclose(fp);
            }
            else if(choice == 2) {
                printf("ID\tName\tGia tri gd tichs luy\tslgd dientu\ttslgd thoi trang\n");
                Inorder_tranver(head);
            }
            else if(choice == 3) {
                printf("Update thong tin:\n");
                printf("nhap thong tin theo truong yeu cau:");
                scanf("%s %s %ld %ld", ID, name, &electronic, &fashion);
                if(electronic<0||fashion<0){
                    printf("wrong data input.\n");
                }
                else{
                cur=Search(head, ID);
                if(cur==NULL){
                    head=Insertion(head, Make_new_node(ID, name, electronic, fashion));
                }
                else if(cur!=NULL){
                    printf("dung r");
                    cur=Input(cur, electronic, fashion);
                       
                }
                printf("cap nhat thanh cong!.");

                }
            }
            else if(choice == 4) {
                Min=postorder(head, Min);
                printf("Best customer:\n");
                printf("ID\tName\tGia tri gd tichs luy\tslgd dientu\ttslgd thoi trang\n");
                printf("%s\t%s\t%d\t%ld\t%ld\n", Min->ID, Min->name, Min->total, Min->num_electronic, Min->num_fashion);

            }
        } while(choice != 0);
    } while(choice < 0 && choice > 4);  

    return 0;  
}

