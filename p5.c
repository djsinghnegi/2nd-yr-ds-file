
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
struct queue{
	int arr[MAXSIZE];
	int front;
	int rear;
	int size;
};
void enqueue(struct queue*);
void dequeue(struct queue*);
void display(struct queue* );
int main(){
	int choice;
	struct queue q1;
	q1.size = 0;
	do{
		printf("\n1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enqueue(&q1);
				break;
			case 2:
				dequeue(&q1);
				break;
			case 3:
				display(&q1);
				break;
			default:
				break;
		}

	}while(choice<4&&choice>0);
	return 0;
}
void enqueue(struct queue * q){
	if(q->size == MAXSIZE){
		printf("\nOverflow\n");
		return;
	}
	int data;
	printf("Enter value to be inserted : ");
	scanf("%d",&data);
	if(q->size == 0){
		q->front = q->rear = 0;
		
	}
	else
		q->rear = (q->rear + 1)%MAXSIZE;

	q->arr[q->rear] = data;
	q->size++;
}
void dequeue(struct queue * q){
	if(q->size == 0){
		printf("\nUnderFlow\n");
		return;
	}
	int data = q->arr[q->front];
	q->front = (q->front + 1)%MAXSIZE;
	q->size--;
	printf("\n%d removed from queue\n",data);
}
void display(struct queue * q){
	printf("\n");
	if(!q->size){
		printf("Empty Queue!!!\n");
		return;
	}
	int temp = q->front;
	int i = 0;
	for( ; i<q->size ; i++){
		printf("%d ",q->arr[temp]);
		temp = (temp + 1)%MAXSIZE;
	}
	printf("\n");
}
