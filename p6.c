#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};	
int search(struct node * , int);
struct node * min(struct node *);
struct node * insert(struct node * , int);
struct node * delete(struct node * , int);
int main(){
    struct node * root = NULL;
    int choice;
    do{
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
            {
                int data = 0;
                printf("Enter value to be inserted : ");
                scanf("%d" , &data);
                int isPresent = search(root,data);
                if(isPresent)
                    printf("\n%d already exists in tree\n", data);
                else{
                    root = insert(root,data);
                    printf("\n%d inserted in tree.\n", data);
                }
                break;
            }
            case 2 :
            {
                int data = 0;
                printf("Enter value to be deleted : ");
                scanf("%d",&data);
                int isPresent = search(root,data);
                if(!isPresent)
                    printf("\n%d can’t be deleted.\n",data);
                else{
                    root = insert(root,data);
                    printf("\n%d deleted from tree.\n", data);
                }
                break;
            }
            case 3 :
            {
                int data;
                printf("Enter value to be searched : ");
                scanf("%d",&data);
                int isPresent = search(root,data);
                if(isPresent){
                    printf("\n%d is present in tree.\n", data);
                }
                else{
                    printf("\n%d isn't present in tree.\n", data);
                }
                break;
            }
            default:
                break;
        }
        
    }while(choice>0&&choice<4);
    return 0;
}
int search(struct node * root,int data){
    if(root == NULL)
        return 0;
    if(root->data>data)
        return search(root->left,data);
    else if(root->data<data)
        return search(root->right,data);
    return 1;
}
struct node * min(struct node * root){
    if(root==NULL)
        return NULL;
    struct node * curr = root;
    while(curr->left!=NULL)
        curr=curr->left;
    return curr;
}
struct node * delete(struct node * root, int data){
    if(root == NULL)
        return NULL;
    if(root->data>data){
        root->left = delete(root->left , data);
    }
    else if(root->data<data){
        root->right = delete(root->right , data);
    }
    else{
        if(root->left == NULL){
            struct node * temp = root->right;
            free(root);
            root = temp;
        }
        else if(root->right == NULL){
            struct node * temp = root->left;
            free(root);
            root = temp;
        }
        else{
            struct node * temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right , root->data);
        }
    }
    return root;
}
struct node * insert(struct node * root , int data){
    if(root == NULL){
        root = (struct node * )malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    if(data>root->data){
        root->right = insert(root->right,data);
    }
    else{
        root->left = insert(root->left,data);
    }
    return root;
}

