#include <stdio.h>
#include <stdlib.h>
int n;
int arr[200];
void insert(){
    int k,value;
    printf("Enter insertion index : ");
    scanf("%d",&k);
    if(k>n){
        printf("Invalid insertion\n");
        return;
    }
    printf("Enter value : ");
    scanf("%d",&value);
    
    for(int i = n-1 ; i>=k ; i--){
        arr[i+1] = arr[i];
    }
    arr[k] = value;
    n+=1;
}
void delete(){
    int k;
    printf("Enter deletion index : ");
    scanf("%d",&k);
    
    if(k>n){
        printf("Invalid deletion\n");
        return;
    }
    
    for(int i = k ; i<n ; i++){
        arr[i] = arr[i+1];
    }
    n--;
}
void update(){
    int k,value;
    printf("Enter updation index : ");
    scanf("%d",&k);
    
    if(k>=n){
        printf("Invalid updation\n");
        return;
    }
    
    printf("Enter value : ");
    scanf("%d",&value);
    arr[k] = value;
}
void search(){
    int value;
    printf("Enter element to search : ");
    scanf("%d",&value);
    
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == value){
            printf("Index : %d, Value : %d\n",i,value);
            return;
        }
    }
    printf("Element not found\n");
}
void traverse(){
    for(int i = 0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    printf("Enter size of array : ");
    scanf("%d",&n);
    
    printf("Enter array elements : ");
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    
    int choice;
    do{
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Search\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                update();
                break;
            case 4:
                search();
                break;
            case 5:
                traverse();
                break;
            default:
                break;
        }
    }while(choice <6);
return 0;
}
