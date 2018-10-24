#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[25];
    int rollno,year;
    float marks[5];
    char branch[3];
    float avg;
};
void display(struct student s1){
    printf("\nName : %s\n",s1.name);
    printf("RollNo : %d\n",s1.rollno);
    printf("Year : %d\n",s1.year);
    printf("Branch : %s\n",s1.branch);
    printf("Average : %0.2f\n\n", s1.avg);
    
}

int main() {

    int n;
    printf("Enter no. of students whose data you want to enter : " );
    scanf("%d",&n);

    struct student students[n];
    for(int i = 0 ; i<n ; i++){
        printf("\nEnter details of student %d\n\n",i+1);
        printf("Enter Name : ");
        scanf("%s",students[i].name);
        printf("Enter RollNo : ");
        scanf("%d",&students[i].rollno);
        printf("Enter Year : ");
        scanf("%d",&students[i].year);
        printf("Enter Branch : ");
        scanf("%s",students[i].branch);
        printf("Enter marks in 5 subjects : ");
        students[i].avg = 0;
        for(int j = 0 ; j<5 ; j++){
            scanf("%f",&students[i].marks[j]);
            students[i].avg+=students[i].marks[j];
        }
        students[i].avg*=0.2;
    }

    int r = 0,check = 0;
    printf("\n\nEnter RollNo to be searched : ");
    scanf("%d",&r);
    for(int i = 0 ; i<n; i++){
        if(students[i].rollno == r){
            check = 1;
            display(students[i]);
            break;
        }
    }
    if(!check){
        printf("\nRollNo doesn't exist\n\n");
    }
    return 0;
}
