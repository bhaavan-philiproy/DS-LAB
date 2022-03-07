#include<stdio.h>
int t,q;
int partition(int a[],int p,int r){
	t=a[p];
	q=p;
	for(int i=p+1;i<=r;i++){
		if(a[i]<t){
			a[q++]=a[i];
			a[i]=a[q];
		}
	}
	a[q]=t;
	return q;
}

void qs(int a[],int p,int r){
	if(p<r){
		q=partition(a,p,r);
		qs(a,p,q-1);
		qs(a,q+1,r);
	}
} 
int main(){
	int n,j;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter values:\n");
	for(j=0;j<n;j++){
		scanf("%d",&a[j]);
	}
        qs(a,0,n);
	printf("Sorted Values:\n");
	for(j=0;j<n;j++){
		printf("%d\t",a[j]);
	}
	return 0;
}
