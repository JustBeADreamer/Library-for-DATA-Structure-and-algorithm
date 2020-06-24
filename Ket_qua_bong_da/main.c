#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



typedef struct team_t{
    char name[10];
    int KQ;
    struct team_t* left;
    struct team_t* right;
}Team_t;






int Cong_diem(int ts1, int ts2){
    if(ts1==ts2)
        return 1;
    else if(ts1<ts2)
        return 0;
    else if(ts1>ts2)
        return 3;
}




Team_t* Make_new_node_t(char name[10]){
    Team_t* New;
    New=(Team_t*)malloc(sizeof(Team_t));
    strcpy(New->name, name);
    New->KQ=0;
    New->left=NULL;
    New->right=NULL;
    return New;
}




Team_t* Insertion_t(Team_t* root, Team_t* New){   
    if(root==NULL){
        return New;
    }
    else if(root!=NULL){
    if (strcmp(New->name, root->name)<0) 
        root->left=Insertion_t(root->left, New); 
    else if (strcmp(New->name, root->name)>0)
        root->right=Insertion_t(root->right, New);
    }     
}



Team_t* Search_t(Team_t* root, char name[10]){ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || strcmp(root->name, name)==0) 
       return root; 
     
    // Key is greater than root's key 
    if (strcmp(root->name, name)<0) 
       return Search_t(root->right, name); 
  
    // Key is smaller than root's key 
    return Search_t(root->left, name); 
} 



Team_t* Input_t(Team_t* root, char name1[10], char name2[10], int ts1, int ts2, int* COUNT){
    Team_t* cur1;
    Team_t* cur2;
    cur1=Search_t(root, name1);
    cur2=Search_t(root, name2);
    if(cur1==NULL){
        root=Insertion_t(root, Make_new_node_t(name1));
        *COUNT=*COUNT+1;
        cur1=Search_t(root, name1);
        printf("Them doi %s vao nut thu %d cua Tree tai dia chi %p\n", cur1->name, *COUNT, cur1);
    }
    if(cur2==NULL){
        root=Insertion_t(root, Make_new_node_t(name2));
        *COUNT=*COUNT+1;
        cur2=Search_t(root, name2);
        printf("Them doi %s vao nut thu %d cua Tree tai dia chi %p\n", cur2->name, *COUNT,  cur2);
    }


    cur1=Search_t(root, name1);
    cur2=Search_t(root, name2);
    if(ts1>ts2){
        cur1->KQ=cur1->KQ+3;
            
    }
    else if(ts1==ts2){
        cur1->KQ=cur1->KQ+1;
        cur2->KQ=cur2->KQ+1;       
    }
    else if(ts1<ts2){
        cur2->KQ=cur2->KQ+3;        
    }
    return root;
}



Team_t* find_Min(Team_t* root){
    Team_t* cur=root;
    while(cur->left!=NULL){
        cur=cur->left;
    }
    return cur;
}






void Inorder_tranver(Team_t* root){
    if(root!=NULL){
        Inorder_tranver(root->left); 
        printf("%s\t%d\n", root->name, root->KQ); 
        Inorder_tranver(root->right); 
    }
}


Team_t* Delete_t(Team_t* root, int key){
    Team_t* Temp;
    if(root!=NULL){
        root->left=Delete_t(root->left, key);

        root->right=Delete_t(root->right, key);
        
        if(root==NULL){
            return NULL;
        }
        else if(root->KQ==key){
            if(root->left==NULL){
                Temp=root->right;
                free(root);
                return Temp;
            }
            if(root->right==NULL){
                Temp=root->left;
                free(root);
                return Temp;
            }
            else{
                Temp=find_Min(root->right);
                root->KQ=Temp->KQ;
                strcpy(root->name, Temp->name);
                root->right=Delete_t(root->right, Temp->KQ);
                return root;
            }
        }
    }
    return root;
}


void Write_t(Team_t* root, FILE* fp){
    if(root!=NULL){
        Write_t(root->left, fp); 
            fprintf(fp ,"%s\t%d", root->name, root->KQ);
        Write_t(root->right, fp); 
    }
}



int main(){
    FILE* fp;

    int* COUNT;
    COUNT=(int*)malloc(sizeof(int));
    *COUNT=0;

    char name1[10];
    char name2[10];
    char name[10];
    int ts1, ts2;
    int key;
    int i;

    Team_t* root=NULL;
    Team_t* cur;
    int n;



    printf("Choose what you want to do: \n");
    printf("1: Create Tree.\n");
    printf("2: OutPut Result\n");
    printf("3: Search.\n");
    printf("4: Downleague.\n");
    printf("5: OutPut file.\n");
    scanf("%d", &n);


    switch (n){
        case 1:
            fp=fopen("BongDa.txt", "r");
            while(fscanf(fp ,"%s\t%s\t%d\t%d", name1, name2, &ts1, &ts2)!=EOF){
                root=Input_t(root, name1, name2, ts1, ts2, COUNT);
            }
            fclose(fp);
        case 2:
            Inorder_tranver(root);
        case 3:
            printf("input name: \n");
            scanf("%s%*c", name);
            cur=Search_t(root, name);
            if(cur==NULL){
                printf("the team you searched doesnt exist\n");
            }
            else{
                printf("Found: %s with %d points", cur->name, cur->KQ);
            }
        case 4:
            printf("Input the point X: \n");
            scanf("%d", &key);
            for(i=0; i<key; i++){
                root=Delete_t(root, i);
            }
            Inorder_tranver(root);
        case 5:
            fp=fopen("KetQua.txt", "w");
            Write_t(root, fp);
            fclose(fp);
    }
}
