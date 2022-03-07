#include<stdio.h>

int a[50],h=-1,t=-1, x;

void enQ(int a[]){
	printf("Enter the value to be added :\n");
	scanf("%d",&x);
	if(t<50)
		a[++t]=x;
	if(h==-1)
		h=0;
}

void deQ(int a[]){
	
	if(h==t && h>-1){
		x=a[h];
		h=0;
		t=0;
		printf("Value removed is:%d\n",x);
	}
	if(h<t)
		printf("Value removed is:%d\n",a[h++]);
}

void dsply(int a[]){
	printf("Values in the queue are:\n");
	for(int i=h;i<=t;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

int main(){
	int o,d;
	do{
		printf("Select one option?(1.Insert/2.Delete/3.Display)\n");
		scanf("%d",&o);
		switch(o){
			case 1:enQ(a);
				break;
			case 2:deQ(a);
				break;
			case 3:dsply(a);
				break;
			default:printf("Select valid option\n");
		}
		printf("Do you want to continue?(1 for YES/0 for NO)\n");
		scanf("%d",&d);
		printf("\n");
	}while(d==1);
	return 0;
}
