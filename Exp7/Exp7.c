#include <stdio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack *next;
};

struct stack *s=NULL;
struct stack *temp;
int x;

struct stack* push(){
	printf("Enter number to be pushed:\n");
	scanf("%d",&x);
	temp=(struct stack*)malloc(sizeof(struct stack));
	temp->data=x;
	temp->next=s;
	s=temp;
	temp=NULL;
	return s;	
}

struct stack* pop(){
	if(s==NULL){
		printf("Stack is empty\n");
		return s;
	}
	x=s->data;
	printf("Value poped is:%d\n",x);
	temp=s;
	s=s->next;
	temp->next=NULL;
	free(temp);
	temp=NULL;
	return s;
}

void dsply(struct stack *s){
	if(s==NULL)
		printf("Stack is empty\n");
	else{
		printf("Values in stack are:\n");
		while(s!=NULL){
			printf("%d\t",s->data);
			s=s->next;
		}
		printf("\n");
	}
}

int main(){
	int o,a;
	do{
		printf("Choose the operation to be peformed:(1.Push/2.Pop/3.Display)\n");
		scanf("%d",&o);
		switch(o){
			case 1:s=push();
		               break;
			case 2:s=pop();
			       break;
			case 3:dsply(s);
			       break;
			default:printf("Choose a valid option..\n");
		}
		printf("Do you want to continue?(1 for Yes/0 for No)\n");
		scanf("%d",&a);
		printf("\n");
	}while(a==1);
	return 0;
}
