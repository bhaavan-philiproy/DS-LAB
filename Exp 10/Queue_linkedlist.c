#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct Q{
	struct node *head,*tail;
};

int x;
struct node *temp;
struct Q *q;

struct Q* create_Q(){
	q=(struct Q*)malloc(sizeof(struct Q));
	q->head=NULL;
	q->tail=NULL;
	return q;	
}

void enQ(struct Q *q){
	printf("Enter the value to be added :\n");
	scanf("%d",&x);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(q->head==NULL)
		q->head=temp;
	else
		q->tail->next=temp;
	q->tail=temp;
	temp=NULL;
}

void deQ(struct Q *q){
	if(q->head!=NULL){
		temp=q->head;
		x=temp->data;
		q->head=temp->next;
		temp->next=NULL;
		free(temp);
		temp=NULL;
		if(q->head==NULL)
			q->tail=NULL;
		printf("Value removed is:%d\n",x);
	}
	else
		printf("Queue is empty\n");		
}

void dsply(struct Q *q){
	struct node *crnt=q->head;
	printf("values in the queue are:\n");
	while(crnt){
		printf("%d\t",crnt->data);
		crnt=crnt->next;
	}
	printf("\n");
}

int main(){
	int o,a;
	q=create_Q();
	do{
		printf("Select one option?(1.Insert/2.Delete/3.Display)\n");
		scanf("%d",&o);
		switch(o){
			case 1:enQ(q);
				break;
			case 2:deQ(q);
				break;
			case 3:dsply(q);
				break;
			default:printf("Select valid option\n");
		}
		printf("Do you want to continue?(1 for YES/0 for NO)\n");
		scanf("%d",&a);
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}while(a==1);
	return 0;
}
