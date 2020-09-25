#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

typedef struct list_t{
    char ID[5];
    char name[30];
    long long total;
    long long electronic;
    long long fashion;
    int num_electronic;
    int num_fashion;
    struct list_t* left;
    struct list_t* right;
}Node;


Node* Make_new_node(char ID[5], char name[30], long int electronic, long int fashion){
    Node* New;
    New=(Node*)malloc(sizeof(Node));
    strcpy(New->name, name);
    strcpy(New->ID, ID);

    New->left=NULL;
    New->right=NULL;
    return New;
}


int Is_leaf(Node* Leaf){
    return (Leaf->left==NULL)&&(Leaf->right==NULL);
}


Node* Insertion(Node* root, Node* New){   
    if(root==NULL){
        return New;
    }
    else if(root!=NULL){
    if (strcmp(New->ID, root->ID)<0) 
        root->left=Insertion(root->left, New); 
    else if (strcmp(New->name, root->name)>0)
        root->right=Insertion(root->right, New);
    }     
}







Node* Search_t(Node* root, char ID[5]){ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || strcmp(root->ID, ID)==0) 
       return root; 
     
    // Key is greater than root's key 
    if (strcmp(root->ID, ID)<0) 
       return Search_t(root->right, ID); 
  
    // Key is smaller than root's key 
    return Search_t(root->left, ID); 
} 


Node* find_Max(Node* root){
    Node* cur=root;
    while(cur->right!=NULL){
        cur=cur->right;
    }
    return cur;
}



Node* find_Min(Node* root){
    Node* cur=root;
    while(cur->left!=NULL){
        cur=cur->left;
    }
    return cur;
}


int main ()
{
    FILE* fp;
    char ID[5];
    char name[30];
    long long electronic;
    long long fashion;



    int choice;
    do {
        do {
            printf("Welcome to ICTBestBuy");
            printf("\n\nMENU:\n");
            printf("1: Load Transaction Data.\n");
            printf("2: Show Statistics Data\n");
            printf("3: Manually Add Transaction\n");
            printf("4: Data Analysis\n");
            printf("0: Quit\n");
            
            printf("Your choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                fp=fopen("giaodich.txt", "r");
                while(fscanf(fp, "%s %s %lld %lld", ID, name, &electronic, &fashion)!=EOF){
                    printf("%s\t%s\t%lld\t%lld\n", ID, name, electronic, fashion);
                }




                fclose(fp);
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

