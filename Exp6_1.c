#include <stdio.h>
#include <stdlib.h>
int retn;
int push(int s[],int size,int top,int x){
    if(top<size){ 
        s[++top]=x;
        return top;
    }
    return -1;
}
int pop(int s[],int top){
    if(top<-1)
        printf("Stack is empty");
    else{
       retn=s[top--];
       return(top);
    }
}
void dsply(int s[],int top){
    int t=top;
    if(top<0)
        printf("Stack is empty");
    else{
        printf("Elements are:\n");
        while(t>=0)
            printf("%d\t",s[t--]);
    }
}
int main(){
    int n,i,x,c;
    printf("Enter the size of stack:");
    scanf("%d",&n);
    int a[n],top=-1;
    printf("Enter values to be added:\n");
    for(i=0;i<n;i++){
       scanf("%d",&x);
       top=push(a,n,top,x);
    }
    dsply(a,top);
    printf("\nDo you want to remove values?(1 for yes/0 for no)\n");
    scanf("%d",&c);
    if(c==1){
        top=pop(a,top);
        printf("Value poped is:%d",retn);
        printf("\nNew stack-");
        dsply(a,top);
    }
    return 0;
}
